#pragma once

#include "Shape.h"

namespace Tetris
{
	struct Square : public Shape
	{
		Square(float size, Color color) : size(size) { this->color = color; }

		void Draw(VPVector2 position) override { DrawRectangle(position.x, position.y, size, size, color); }
		float size;
	};
}