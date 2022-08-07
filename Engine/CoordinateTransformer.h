#pragma once

#include <vector>
#include "Graphics.h"
#include "Vec2.h"
#include "Drawable.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx);
	void Draw(Drawable& drawable) const;
private:
	Graphics& gfx;
};
