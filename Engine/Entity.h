#pragma once

#include <vector>
#include "Vec2.h"
#include "Drawable.h"

class Entity
{
public:
	Entity(std::vector<Vec2<float>> model, const Vec2<float> pos = {0.0f, 0.0f}, Color c = Colors::Yellow);
	const Vec2<float> GetPos() const;
	void SetPos(const Vec2<float>& newPos);
	void TranslateBy(const Vec2<float>& offset);
	float GetScale() const;
	void SetScale(float newScale);
	Drawable GetDrawable() const;

private:
	std::vector<Vec2<float>> model;
	Vec2<float> pos;
	float scale = 1.0f;
	Color c;

};
