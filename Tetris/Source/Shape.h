#pragma once

#include "Vector2.h"

#include <raylib.h>

namespace Tetris
{
	struct Shape
	{
		virtual void Draw(VPVector2 position) abstract;
	
		Color color = WHITE;
	};
}

