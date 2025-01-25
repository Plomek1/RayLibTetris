#pragma once

struct Vector2;

namespace Tetris
{
	struct VPVector2
	{
		VPVector2();
		VPVector2(float x, float y);
		VPVector2(Vector2 rayVector);

		float x = 0;
		float y = 0;
	};
}

