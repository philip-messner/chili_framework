#include "Entity.h"

Entity::Entity(std::vector<Vec2<float>> model, const Vec2<float> pos, Color c)
	:
	model(std::move(model)),
	pos( pos ),
	c ( c )

{
	float top = 0.0f;
	float bottom = 0.0f;
	float right = 0.0f;
	float left = 0.0f;
	for (auto vert : model)
	{
		if (vert.x < left)
		{
			left = vert.x;
		}
		if (vert.x > right)
		{
			right = vert.x;
		}
		if (vert.y < bottom)
		{
			bottom = vert.y;
		}
		if (vert.y > top)
		{
			top = vert.y;
		}
	}
	boundingRect = Rect<float>(top, bottom, right, left);
}

const Vec2<float> Entity::GetPos() const
{
	return pos;
}

void Entity::SetPos(const Vec2<float>& newPos)
{
	const Vec2<float> offset = newPos - pos;
	pos = newPos;
	boundingRect.TranslateBy(offset);
}

void Entity::TranslateBy(const Vec2<float>& offset)
{
	pos += offset;
	boundingRect.TranslateBy(offset);
}


float Entity::GetScale() const
{
	return scale;
}

void Entity::SetScale(float newScale)
{
	float factor = newScale / scale;
	scale = newScale;
	boundingRect.Scale(factor);
}

Color Entity::GetColor() const
{
	return c;
}

void Entity::SetColor(Color newColor)
{
	c = newColor;
}

Drawable Entity::GetDrawable() const
{
	Drawable d(model, c);
	d.Scale(scale);
	d.Translate(pos);

	return d;
}

Rect<float> Entity::GetBoundingRect() const
{
	return Rect<float>();
}
