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
	entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2<float>(450.0f, 0.0f));
	entities.emplace_back(Star::Make(150.0f, 50.0f), Vec2<float>(150.0f, 100.0f));
	entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2<float>(250.0f, -200.0f));
	entities.emplace_back(Star::Make(150.0f, 50.0f), Vec2<float>(-250.0f, 200.0f));
	entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2<float>(0.0f, 0.0f));
	entities.emplace_back(Star::Make(200.0f, 50.0f), Vec2<float>(-150.0f, -300.0f));
	entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2<float>(400.0f, 300.0f));
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
	for (const auto& entity : entities)
	{
		cam.Draw(entity.GetDrawable());
	}
}
