#include "Drawable.h"

Drawable::Drawable(std::vector<Vec2<float>> model, Color c)
	:
	model(std::move(model)),
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

void Drawable::Render(Graphics& gfx)
{
	for (auto& v : model)
	{
		v.x *= scale_x;
		v.y *= scale_y;
		v += translation;
	}
	gfx.DrawClosedPolyline(model, c);
}
