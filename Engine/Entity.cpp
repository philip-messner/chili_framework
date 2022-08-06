#include "Entity.h"

Entity::Entity(std::vector<Vec2<float>> model, const Vec2<float> pos)
	:
	model(std::move(model)),
	pos( pos )
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

std::vector<Vec2<float>> Entity::GetPolyLine() const
{
	auto poly = model;
	for (auto& v : poly)
	{
		v *= scale;
		v += pos;
	}
	return poly;
}

float Entity::GetScale() const
{
	return scale;
}

void Entity::SetScale(float newScale)
{
	scale = newScale;
}
