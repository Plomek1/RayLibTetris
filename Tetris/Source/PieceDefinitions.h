#pragma once

#include "Vector2.h"

#include <vector>
#include <raylib.h>

namespace Tetris
{
	struct PieceDefinition
	{
		const int rotationCount;
		VPVector2 spawnOffset;
		Color color;

		std::vector<std::vector<VPVector2>> rotations;
	};

	PieceDefinition pieceI
	{
		.rotationCount = 2,
		.spawnOffset = VPVector2(0, -2),
		.color = Color(50,198,239,255),
		.rotations{
			std::vector<VPVector2>
			{
				VPVector2(0, 2),
				VPVector2(1, 2),
				VPVector2(2, 2),
				VPVector2(3, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(2, 0),
				VPVector2(2, 1),
				VPVector2(2, 2),
				VPVector2(2, 3),
			}
		}
	};

	PieceDefinition pieceJ
	{
	.rotationCount = 4,
	.spawnOffset = VPVector2(0, 0),
	.color = Color(91,100,173,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
				VPVector2(2, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(0, 2),
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(0, 0),
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
			},

			std::vector<VPVector2>
			{
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
				VPVector2(2, 0),
			}
		}
	};
}