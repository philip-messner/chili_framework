#pragma once

#include <vector>
#include "Vec2.h"

class Entity
{
public:
	Entity(std::vector<Vec2<float>> model);
	const Vec2<float> GetPos() const;
	void SetPos(const Vec2<float>& newPos);
	void TranslateBy(const Vec2<float>& offset);
	std::vector<Vec2<float>> GetPolyLine() const;

private:
	std::vector<Vec2<float>> model;
	Vec2<float> pos;

};
