#include "CoordinateTransformer.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
	:
	gfx(gfx)
{}

void CoordinateTransformer::DrawClosedPolyline(std::vector<Vec2<float>> poly, Color c)
{
	Vec2<float> offset((float)(Graphics::ScreenWidth / 2), (float)(Graphics::ScreenHeight / 2));
	for (auto& v : poly)
	{
		v.y *= -1.0f;
		v += offset;
	}
	gfx.DrawClosedPolyline(poly, c);
}

