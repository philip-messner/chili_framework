#pragma once

#include <vector>
#include "Vec2.h"
#include "CoordinateTransformer.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct);
	Vec2<float> GetPos() const;
	void MoveBy(const Vec2<float>& offset);
	void MoveTo(const Vec2<float>& newPos);
	void DrawClosedPolyline(std::vector<Vec2<float>> poly, Color c);
private:
	Vec2<float> pos = {0.0f, 0.0f};
	CoordinateTransformer& ct;
};

