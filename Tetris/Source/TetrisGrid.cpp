#include "TetrisGrid.h"

#include "Globals.h"

#include <raylib.h>

namespace Tetris
{
	void TetrisGrid::Update(float deltaTime)
	{
		DrawGrid();
	}

	void TetrisGrid::DrawGrid()
	{
		if (!drawGrid) return;

		VPVector2 windowSize = Globals::windowParameters.windowSize;

		int cellSize = windowSize.y / gridHeight;

		for (int i = 0; i <= gridHeight; i++)
		{
			int linePosY = i * cellSize;
			DrawLine(0, linePosY, windowSize.x * .666, linePosY, GRAY);
		}

		for (int i = 0; i <= gridWidth; i++)
		{
			int linePosX = i * cellSize;
			DrawLine(linePosX, 0, linePosX, windowSize.y, GRAY);
		}
	}
}

