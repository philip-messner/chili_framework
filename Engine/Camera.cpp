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

void Camera::Draw(Drawable& drawable) const
{
	drawable.Translate(pos * -1.0f);
	drawable.Scale(zoom);
	ct.Draw(drawable);
}

void Camera::SetZoom(const float newZoom)
{
	zoom = newZoom;
}

float Camera::GetZoom() const
{
	return zoom;
}
