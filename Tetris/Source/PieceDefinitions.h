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
	.spawnOffset = VPVector2(0, -1),
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

	PieceDefinition pieceL
	{
	.rotationCount = 4,
	.spawnOffset = VPVector2(0, -1),
	.color = Color(241,122,34,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
				VPVector2(0, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(0, 0),
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(2, 0),
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
			},

			std::vector<VPVector2>
			{
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
				VPVector2(2, 2),
			}
		}
	};

	PieceDefinition pieceO
	{
	.rotationCount = 1,
	.spawnOffset = VPVector2(0, 0),
	.color = Color(246,210,8,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 0),
				VPVector2(0, 1),
				VPVector2(1, 0),
				VPVector2(1, 1),
			}
		}
	};

	PieceDefinition pieceS
	{
	.rotationCount = 2,
	.spawnOffset = VPVector2(0, -1),
	.color = Color(67,182,67,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 2),
				VPVector2(1, 2),
				VPVector2(1, 1),
				VPVector2(2, 1),
			},

			std::vector<VPVector2>
			{
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(2, 1),
				VPVector2(2, 2),
			}
		}
	};

	PieceDefinition pieceT
	{
	.rotationCount = 4,
	.spawnOffset = VPVector2(0, -1),
	.color = Color(172,77,157,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
				VPVector2(1, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
				VPVector2(0, 1),
			},

			std::vector<VPVector2>
			{
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(2, 1),
				VPVector2(1, 0),
			},

			std::vector<VPVector2>
			{
				VPVector2(1, 0),
				VPVector2(1, 1),
				VPVector2(1, 2),
				VPVector2(2, 1),
			}
		}
	};

	PieceDefinition pieceZ
	{
	.rotationCount = 2,
	.spawnOffset = VPVector2(0, -1),
	.color = Color(238,33,41,255),
	.rotations
		{
			std::vector<VPVector2>
			{
				VPVector2(0, 1),
				VPVector2(1, 1),
				VPVector2(1, 2),
				VPVector2(2, 2),
			},

			std::vector<VPVector2>
			{
				VPVector2(2, 0),
				VPVector2(2, 1),
				VPVector2(1, 1),
				VPVector2(1, 2),
			}
		}
	};
}