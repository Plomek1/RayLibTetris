#pragma once

#include "Shape.h"

namespace Tetris
{
	struct Rectangle : public Shape
	{
		Rectangle(VPVector2 size, Color color) : size(size) { this->color = color; }

		void Draw(VPVector2 position) override { DrawRectangle(position.x, position.y, size.x, size.y, color); }
		VPVector2 size;
	};
}