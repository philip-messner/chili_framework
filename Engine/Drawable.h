#pragma once

#include <vector>
#include "Vec2.h"
#include "Graphics.h"

class Drawable
{
public:
	Drawable(std::vector<Vec2<float>> model, Color c);
	void Translate(const Vec2<float>& translate_in);
	void Scale(float scale_in);
	void ScaleIndependent(float scale_in_x, float scale_in_y);
	void Render(Graphics& gfx);

private:
	std::vector<Vec2<float>> model;
	Vec2<float> translation = {0.0f, 0.0f};
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	Color c;
};