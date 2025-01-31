#pragma once
#include "Component.h"

#include "Vector2.h"

#include <vector>

namespace Tetris
{
	class TetrisGrid : public Component
	{
	public:
		TetrisGrid(Game& game, const uint32_t id, GameObject& root, int cellSize = 16)
			: Component(game, id, root), cellSize(cellSize), cells(std::vector<GameObject*>(gridHeight * gridWidth)) {}

		GameObject* GetCell(const uint32_t index) const;
		inline GameObject* GetCell(const VPVector2 coordinates) const 
		{ return IsInBounds(coordinates) ? GetCell(GetCellIndex(coordinates)) : nullptr; }
		inline GameObject* GetCell(const uint32_t x, const uint32_t y) const 
		{ return IsInBounds(x, y) ? GetCell(GetCellIndex(x, y)) : nullptr; }

		bool SetCell(GameObject* gameObject, const uint32_t index);
		inline bool SetCell(GameObject* gameObject, const VPVector2 coordinates) 
		{ return IsInBounds(coordinates) ? SetCell(gameObject, GetCellIndex(coordinates)) : false; }
		inline bool SetCell(GameObject* gameObject, const uint32_t x, const uint32_t y) 
		{ return IsInBounds(x, y) ? SetCell(gameObject, GetCellIndex(x, y)) : false; }

		bool MoveCell(const uint32_t startIndex, const uint32_t targetIndex);
		bool MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates);
		bool MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY);

		inline VPVector2 GetCellWorldPosition(const VPVector2 coordinates) const 
		{ return VPVector2(coordinates.x * cellSize, coordinates.y * cellSize); }
		inline VPVector2 GetCellWorldPosition(const uint32_t x, const uint32_t y) const 
		{ return VPVector2(x * cellSize, y * cellSize); }

		inline bool IsInBounds(const uint32_t index) const 
		{ return index >= 0 && index < cells.size(); }
		inline bool IsInBounds(VPVector2 coordinates) const 
		{ return coordinates.x >= 0 && coordinates.x < gridWidth && coordinates.y >= 0 && coordinates.y < gridHeight; }
		inline bool IsInBounds(const uint32_t x, const uint32_t y) const 
		{ return x >= 0 && x < gridWidth && y >= 0 && y < gridHeight; }

		void Update(float deltaTime) override;

		uint32_t cellSize;

	private:
		void DrawGrid();

		inline uint32_t GetCellIndex(const VPVector2 coordinates) const { return coordinates.x + coordinates.y * gridWidth; }
		inline uint32_t GetCellIndex(const uint32_t x, const uint32_t y) const { return x + y * gridWidth; }


		unsigned const int gridWidth  = 10;
		unsigned const int gridHeight = 20;

		std::vector<GameObject*> cells;

		bool drawGrid = true;
	};
}

