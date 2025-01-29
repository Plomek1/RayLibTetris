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
		inline GameObject* GetCell(const VPVector2 coordinates) const { return GetCell(GetCellIndex(coordinates)); }
		inline GameObject* GetCell(const uint32_t x, const uint32_t y) const { return GetCell(GetCellIndex(x, y)); }

		bool SetCell(GameObject* gameObject, const uint32_t index);
		inline bool SetCell(GameObject* gameObject, const VPVector2 coordinates) { return SetCell(gameObject, GetCellIndex(coordinates)); }
		inline bool SetCell(GameObject* gameObject, const uint32_t x, const uint32_t y) { return SetCell(gameObject, GetCellIndex(x, y)); }

		bool MoveCell(const uint32_t startIndex, const uint32_t targetIndex);
		inline bool MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates) 
		{ return MoveCell(GetCellIndex(startCoordinates), GetCellIndex(targetCoordinates)); }
		inline bool MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY) 
		{ return MoveCell(GetCellIndex(startX, startY), GetCellIndex(targetX, startY)); }

		inline VPVector2 GetCellWorldPosition(const VPVector2 coordinates) const { return VPVector2(coordinates.x * cellSize, coordinates.y * cellSize); }
		inline VPVector2 GetCellWorldPosition(const uint32_t x, const uint32_t y) const { return VPVector2(x * cellSize, y * cellSize); }

		inline bool IsInBounds(const uint32_t index) const { return index >= 0 && index < cells.size(); }
		inline bool IsInBounds(VPVector2 coordinates) { return IsInBounds(GetCellIndex(coordinates)); }
		inline bool IsInBounds(const uint32_t x, const uint32_t y) { return IsInBounds(GetCellIndex(x, y)); }

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

