#pragma once

#include "Shape.h"

namespace Tetris
{
	struct Circle : public Shape 
	{
		Circle() : radius(1) {}
		Circle(float radius, Color color) : radius(radius) { this->color = color; }

		void Draw(VPVector2 position) override { DrawCircle(position.x, position.y, radius, color); }
		float radius;
	};
}