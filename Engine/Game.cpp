/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Star.h"
#include "CoordinateTransformer.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ct(gfx),
	cam(ct)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> xDist(-worldWidth / 2.0f, worldWidth / 2.0f);
	std::uniform_real_distribution<float> yDist(-worldHeight / 2.0f, worldHeight / 2.0f);
	std::normal_distribution<float> radDist(meanStarRadius, devStarRadius);
	std::normal_distribution<float> ratDist(meanInnerRatio, devInnerRatio);
	std::normal_distribution<float> flareDist(meanFlares, devFlares);
	const Color colors[] = { Colors::Red, Colors::White, Colors::Blue, Colors::Cyan, Colors::Yellow, Colors::Green };
	std::uniform_int_distribution<size_t> colorSampler(0, std::end(colors) - std::begin(colors));
	while (stars.size() < nStars)
	{
		const auto rad = std::clamp(radDist(rng), minStarRadius, maxStarRadius);
		const Vec2<float> pos = { xDist(rng), yDist(rng) };
		if (std::any_of(stars.begin(), stars.end(), [&](const StarBro& sb)
			{ return (sb.GetPos() - pos).GetLength() < rad + sb.GetRadius(); }))
		{
			continue;
		}
		const auto rat = std::clamp(ratDist(rng), minInnerRatio, maxInnerRatio);
		const Color c = colors[colorSampler(rng)];
		const int nFlares = std::clamp((int)flareDist(rng), minFlares, maxFlares);
		stars.emplace_back(pos, rad, rat, nFlares, c);
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float speed = 3.0f;
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		cam.MoveBy({ 0.0f, -1.0f * speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		cam.MoveBy({ 0.0f, speed });
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		cam.MoveBy({ -1.0f * speed, 0.0f });
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		cam.MoveBy({ speed, 0.0f });
	}
	if (wnd.kbd.KeyIsPressed('Q'))
	{
		cam.SetZoom(cam.GetZoom() * 1.05f);
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		cam.SetZoom(cam.GetZoom() * 0.95f);
	}
}

void Game::ComposeFrame()
{
	for (const auto& star : stars)
	{
		cam.Draw(star.GetDrawable());
	}
}
