#pragma once
#include "Component.h"

#include "Vector2.h"

#include <vector>

namespace Tetris
{
	class TetrisGrid : public Component
	{
	public:
		TetrisGrid(Game& game, GameObject& root, int cellSize = 16) : Component(game, root), cellSize(cellSize), cells(std::vector<GameObject*>(gridHeight * gridWidth)) {}
		void Update(float deltaTime) override;

		GameObject* GetCell(const unsigned int index) const;
		inline GameObject* GetCell(const VPVector2 coordinates) const { return GetCell(GetCellIndex(coordinates)); }
		inline GameObject* GetCell(const unsigned int x, const unsigned int y) const { return GetCell(GetCellIndex(x, y)); }

		bool SetCell(GameObject* gameObject, const unsigned int index);
		inline bool SetCell(GameObject* gameObject, const VPVector2 coordinates) { return SetCell(gameObject, GetCellIndex(coordinates)); }
		inline bool SetCell(GameObject* gameObject, const unsigned int x, const unsigned int y) { return SetCell(gameObject, GetCellIndex(x, y)); }

		bool MoveCell(const unsigned int startIndex, const unsigned int targetIndex);
		inline bool MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates) 
		{ return MoveCell(GetCellIndex(startCoordinates), GetCellIndex(targetCoordinates)); }
		inline bool MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY) 
		{ return MoveCell(GetCellIndex(startX, startY), GetCellIndex(targetX, startY)); }

		inline VPVector2 GetCellWorldPosition(const VPVector2 coordinates) const { return VPVector2(coordinates.x * cellSize, coordinates.y * cellSize); }
		inline VPVector2 GetCellWorldPosition(const unsigned int x, const unsigned int y) const { return VPVector2(x * cellSize, y * cellSize); }

		unsigned int cellSize;

	private:
		void DrawGrid();

		inline unsigned int GetCellIndex(const VPVector2 coordinates) const { return coordinates.x + coordinates.y * gridWidth; }
		inline unsigned int GetCellIndex(const unsigned int x, const unsigned int y) const { return x + y * gridWidth; }

		inline bool ValidateIndex(const unsigned int index) const { return index >= 0 && index < cells.size(); }

		unsigned const int gridWidth  = 10;
		unsigned const int gridHeight = 20;

		std::vector<GameObject*> cells;

		bool drawGrid = true;
	};
}

