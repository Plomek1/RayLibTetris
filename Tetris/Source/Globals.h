#pragma once

#include "Vector2.h"

namespace Tetris::Globals
{
	struct WindowParameters
	{
		VPVector2 windowSize;
		VPVector2 mousePos;
	};

	extern WindowParameters windowParameters;
}