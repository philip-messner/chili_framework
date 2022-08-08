#pragma once

#include <vector>
#include "Vec2.h"
#include "Drawable.h"
#include "Rect.h"

class Entity
{
public:
	Entity(std::vector<Vec2<float>> model, const Vec2<float> pos = {0.0f, 0.0f}, Color c = Colors::Yellow);
	const Vec2<float> GetPos() const;
	void SetPos(const Vec2<float>& newPos);
	void TranslateBy(const Vec2<float>& offset);
	float GetScale() const;
	void SetScale(float newScale);
	Color GetColor() const;
	void SetColor(Color newColor);
	Drawable GetDrawable() const;
	Rect<float> GetBoundingRect() const;

private:
	std::vector<Vec2<float>> model;
	Vec2<float> pos;
	float scale = 1.0f;
	Color c;
	Rect<float> boundingRect = {0.0f, 0.0f, 0.0f, 0.0f};
};
