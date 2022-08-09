#pragma once

#include "Camera.h"
#include "Mouse.h"
#include "Vec2.h"

class MouseCameraController
{
public:
	MouseCameraController(Mouse& mouse, Camera& cam)
		:
		mouse(mouse),
		cam(cam)
	{}
	void Update()
	{
		while (!mouse.IsEmpty())
		{
			const auto e = mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::LPress:
				engaged = true;
				lastPos = Vec2<float>(e.GetPosX(), e.GetPosY());
				break;
			case Mouse::Event::Type::LRelease:
				engaged = false;
				break;
			case Mouse::Event::Type::WheelUp:
				cam.SetZoom(cam.GetZoom() * zoomFactor);
				break;
			case Mouse::Event::Type::WheelDown:
				cam.SetZoom(cam.GetZoom() / zoomFactor);
				break;
			}
		}

		if (engaged)
		{
			const auto curPos = Vec2<float>(mouse.GetPosX(), mouse.GetPosY());
			auto delta = curPos - lastPos;
			delta.x = -delta.x; // fixes the disconnect between screen coords and math coords
			cam.MoveBy(delta / cam.GetZoom());
			lastPos = curPos;
		}
	}
private:
	static constexpr float zoomFactor = 1.05f;
	bool engaged = false;
	Vec2<float> lastPos;
	Mouse& mouse;
	Camera& cam;
};