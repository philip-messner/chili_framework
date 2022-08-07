#pragma once

#include <vector>
#include "Vec2.h"
#include "CoordinateTransformer.h"
#include "Drawable.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct);
	Vec2<float> GetPos() const;
	void MoveBy(const Vec2<float>& offset);
	void MoveTo(const Vec2<float>& newPos);
	void Draw(Drawable& drawable) const;
	void SetZoom(const float newZoom);
	float GetZoom() const;
private:
	Vec2<float> pos = {0.0f, 0.0f};
	CoordinateTransformer& ct;
	float zoom = 1.0f;
};

