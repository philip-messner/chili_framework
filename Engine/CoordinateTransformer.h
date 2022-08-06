#pragma once

#include <vector>
#include "Graphics.h"
#include "Vec2.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx);
	void DrawClosedPolyline(std::vector<Vec2<float>> poly, Color c);
private:
	Graphics& gfx;
};
