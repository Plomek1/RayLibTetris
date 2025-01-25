#include "Vector2.h"

#include <raylib.h>

namespace Tetris
{
	VPVector2::VPVector2() {}
	VPVector2::VPVector2(float x, float y) : x(x), y(y) {}
	VPVector2::VPVector2(Vector2 rayVector) : x(rayVector.x), y(rayVector.y) {}
}

