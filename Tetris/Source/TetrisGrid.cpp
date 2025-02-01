#include "TetrisGrid.h"

#include "Block.h"

#include <raylib.h>
#include <iostream>

namespace Tetris
{
	void TetrisGrid::Update(float deltaTime)
	{
		DrawGrid();
	}

	Block* TetrisGrid::GetCell(const uint32_t index) const
	{
		bool indexValid = IsInBounds(index);
		return indexValid ? cells[index] : nullptr;
	}

	bool TetrisGrid::SetCell(Block* gameObject, const uint32_t index)
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
			Block* moveBlock = GetCell(startIndex);
			SetCell(nullptr, startIndex);
			SetCell(moveBlock, targetIndex);
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

	void TetrisGrid::ClearFullLines()
	{
		int linesCleared = 0;
		int y = height;
		for (y; y >= 0; y--)
		{
			if (IsLineFull(y))
			{
				ClearLine(y);
				linesCleared++;
				continue;
			}
			
			if (linesCleared > 0)
				break;
		}
		
		if (linesCleared > 0)
		{
			for (y; y >= 0; y--)
				MoveLine(y, linesCleared);
		}

		std::cout << linesCleared << std::endl;
	}

	void TetrisGrid::MoveLine(int y, int yDifference)
	{
		for (int x = 0; x < width; x++)
		{
			if (Block* block = GetCell(x, y))
			{
				block->Move(VPVector2(x, y + yDifference));
				block->Lock();
				SetCell(nullptr, x, y);
			}
		}
	}

	void TetrisGrid::ClearLine(int y)
	{
		for (int x = 0; x < width; x++)
		{
			Destroy(GetCell(x, y)->root.id);
			SetCell(nullptr, x, y);
		}
	}

	bool TetrisGrid::IsLineFull(int y)
	{
		for (int x = 0; x < width; x++)
		{
			if (!GetCell(x, y))
				return false;
		}
		return true;
	}

	void TetrisGrid::DrawGrid()
	{
		if (!drawGrid) return;

		int lineLength = width * cellSize;
		for (int i = 0; i <= height; i++)
		{
			int linePosY = i * cellSize;
			DrawLine(0, linePosY, lineLength, linePosY, GRAY);
		}

		lineLength = height * cellSize;
		for (int i = 0; i <= width; i++)
		{
			int linePosX = i * cellSize;
			DrawLine(linePosX, 0, linePosX, lineLength, GRAY);
		}
	}
}

