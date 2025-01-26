#include "TetrisGrid.h"

#include "Globals.h"

#include <raylib.h>

namespace Tetris
{
	void TetrisGrid::Update(float deltaTime)
	{
		DrawGrid();
	}

	GameObject* TetrisGrid::GetCell(const unsigned int index) const
	{
		return cells.size() > index ? cells[index] : nullptr;
	}

	GameObject* TetrisGrid::GetCell(const VPVector2 coordinates) const
	{
		unsigned int index = GetCellIndex(coordinates);
		return cells.size() > index ? cells[index] : nullptr;
	}

	GameObject* TetrisGrid::GetCell(const unsigned int x, const unsigned int y) const
	{
		unsigned int index = GetCellIndex(x, y);
		return cells.size() > index ? cells[index] : nullptr;
	}

	void TetrisGrid::SetCell(GameObject* gameObject, const unsigned int index)
	{
		if (cells.size() > index) cells[index] = gameObject;
	}

	void TetrisGrid::SetCell(GameObject* gameObject, const VPVector2 coordinates)
	{
		unsigned int index = GetCellIndex(coordinates);
		if (cells.size() > index) cells[index] = gameObject;
	}

	void TetrisGrid::SetCell(GameObject* gameObject, const unsigned int x, const unsigned int y)
	{
		unsigned int index = GetCellIndex(x, y);
		if (cells.size() > index) cells[index] = gameObject;
	}

	void TetrisGrid::MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates)
	{
		int startIndex = GetCellIndex(startCoordinates);
		GameObject* moveObject = GetCell(startIndex);
		SetCell(nullptr, startIndex);
		SetCell(moveObject, targetCoordinates);
	}

	void TetrisGrid::MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY)
	{
		int startIndex = GetCellIndex(startX, startY);
		GameObject* moveObject = GetCell(startIndex);
		SetCell(nullptr, startIndex);
		SetCell(moveObject, targetX, targetY);
	}

	void TetrisGrid::DrawGrid()
	{
		if (!drawGrid) return;

		VPVector2 windowSize = Globals::windowParameters.windowSize;

		int cellSize = windowSize.y / gridHeight;

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

