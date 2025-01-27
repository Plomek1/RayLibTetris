#include "TetrisGrid.h"

#include <raylib.h>

namespace Tetris
{
	void TetrisGrid::Update(float deltaTime)
	{
		DrawGrid();
	}

	GameObject* TetrisGrid::GetCell(const unsigned int index) const
	{
		bool indexValid = ValidateIndex(index);
		return indexValid ? cells[index] : nullptr;
	}

	bool TetrisGrid::SetCell(GameObject* gameObject, const unsigned int index)
	{
		if (ValidateIndex(index))
		{
			cells[index] = gameObject;
			return true;
		}
		return false;
	}

	bool TetrisGrid::MoveCell(const unsigned int startIndex, const unsigned int targetIndex)
	{
		if (ValidateIndex(startIndex) && ValidateIndex(targetIndex))
		{
			GameObject* moveObject = GetCell(startIndex);
			SetCell(nullptr, startIndex);
			SetCell(moveObject, targetIndex);
			return true;
		}
		return false;
	}

	void TetrisGrid::DrawGrid()
	{
		if (!drawGrid) return;

		int lineLength = gridWidth * cellSize;
		for (int i = 0; i <= gridHeight; i++)
		{
			int linePosY = i * cellSize;
			DrawLine(0, linePosY, lineLength, linePosY, GRAY);
		}

		lineLength = gridHeight * cellSize;
		for (int i = 0; i <= gridWidth; i++)
		{
			int linePosX = i * cellSize;
			DrawLine(linePosX, 0, linePosX, lineLength, GRAY);
		}
	}
}

