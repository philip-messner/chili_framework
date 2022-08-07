#include "CoordinateTransformer.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
	:
	gfx(gfx)
{}

void CoordinateTransformer::Draw(Drawable& drawable) const
{
	const Vec2<float> offset((float)(Graphics::ScreenWidth / 2), (float)(Graphics::ScreenHeight / 2));
	
	drawable.ScaleIndependent(1.0f, -1.0f);
	drawable.Translate(offset);
	drawable.Render(gfx);
}

