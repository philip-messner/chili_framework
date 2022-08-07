#include "StarBro.h"

StarBro::StarBro(Vec2<float> pos, float radius, float innerRatio, int nFlares, Color c)
	:
	Entity(Star::Make(radius, radius* innerRatio, nFlares), pos, c),
	radius(radius)
{}

float StarBro::GetRadius() const
{
	return radius;
}
