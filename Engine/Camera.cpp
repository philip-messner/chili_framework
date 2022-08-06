#include "Camera.h"

Camera::Camera(CoordinateTransformer& ct)
	:
	ct( ct )
{}

Vec2<float> Camera::GetPos() const
{
	return pos;
}

void Camera::MoveBy(const Vec2<float>& offset)
{
	pos += offset;
}

void Camera::MoveTo(const Vec2<float>& newPos)
{
	pos = newPos;
}

void Camera::DrawClosedPolyline(std::vector<Vec2<float>> poly, Color c)
{
	for (auto& v : poly)
	{
		v -= pos;
		v *= zoom;
	}
	ct.DrawClosedPolyline(std::move(poly), c);
}

void Camera::SetZoom(const float newZoom)
{
	zoom = newZoom;
}

float Camera::GetZoom() const
{
	return zoom;
}
