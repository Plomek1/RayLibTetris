#include "TetrisGrid.h"

#include <raylib.h>

namespace Tetris
{
	void TetrisGrid::Update(float deltaTime)
	{
		DrawGrid();
	}

	GameObject* TetrisGrid::GetCell(const uint32_t index) const
	{
		bool indexValid = IsInBounds(index);
		return indexValid ? cells[index] : nullptr;
	}

	bool TetrisGrid::SetCell(GameObject* gameObject, const uint32_t index)
	{
		if (IsInBounds(index))
		{
			cells[index] = gameObject;
			return true;
		}
		return false;
	}

	bool TetrisGrid::MoveCell(const uint32_t startIndex, const uint32_t targetIndex)
	{
		if (IsInBounds(startIndex) && IsInBounds(targetIndex))
		{
			GameObject* moveObject = GetCell(startIndex);
			SetCell(nullptr, startIndex);
			SetCell(moveObject, targetIndex);
			return true;
		}
		return false;
	}

	bool TetrisGrid::MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates)
	{
		if (IsInBounds(startCoordinates) && IsInBounds(targetCoordinates))
			return MoveCell(GetCellIndex(startCoordinates), GetCellIndex(targetCoordinates));
		return false;
	}

	bool TetrisGrid::MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY)
	{
		if (IsInBounds(startX, startY) && IsInBounds(targetX, targetY))
			return MoveCell(GetCellIndex(startX, startY), GetCellIndex(targetX, startY));
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

