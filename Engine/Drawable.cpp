#include "Drawable.h"

Drawable::Drawable(const std::vector<Vec2<float>>& model, Color c)
	:
	model(&model),
	c( c )
{}

void Drawable::Translate(const Vec2<float>& translate_in)
{
	translation += translate_in;
}

void Drawable::Scale(float scale_in)
{
	scale_x *= scale_in;
	scale_y *= scale_in;
	translation *= scale_in;
}

void Drawable::ScaleIndependent(float scale_in_x, float scale_in_y)
{
	scale_x *= scale_in_x;
	scale_y *= scale_in_y;
	translation.x *= scale_in_x;
	translation.y *= scale_in_y;
}

void Drawable::Render(Graphics& gfx) const
{
	gfx.DrawClosedPolyline(*model, translation, scale_x, scale_y, c);
}
