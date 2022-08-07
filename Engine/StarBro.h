#pragma once

#include "Entity.h"
#include "Star.h"
#include "Vec2.h"

class StarBro : public Entity
{
public:
	StarBro(Vec2<float> pos, float radius, float innerRatio, int nFlares, Color c);
	float GetRadius() const;
private:
	float radius;
};