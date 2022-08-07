#include "Entity.h"

Entity::Entity(std::vector<Vec2<float>> model, const Vec2<float> pos, Color c)
	:
	model(std::move(model)),
	pos( pos ),
	c ( c )

{}

const Vec2<float> Entity::GetPos() const
{
	return pos;
}

void Entity::SetPos(const Vec2<float>& newPos)
{
	pos = newPos;
}

void Entity::TranslateBy(const Vec2<float>& offset)
{
	pos += offset;
}


float Entity::GetScale() const
{
	return scale;
}

void Entity::SetScale(float newScale)
{
	scale = newScale;
}

Drawable Entity::GetDrawable() const
{
	Drawable d(model, c);
	d.Scale(scale);
	d.Translate(pos);

	return d;
}
