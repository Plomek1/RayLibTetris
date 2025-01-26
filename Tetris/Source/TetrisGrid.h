#pragma once
#include "Component.h"

#include "Vector2.h"

#include <vector>

namespace Tetris
{
	class TetrisGrid : public Component
	{
	public:
		TetrisGrid(Game& game, GameObject& root) : Component(game, root), cells(std::vector<GameObject*>(gridHeight * gridWidth)) {}
		void Update(float deltaTime) override;

		GameObject* GetCell(const unsigned int index) const;
		GameObject* GetCell(const VPVector2 coordinates) const;
		GameObject* GetCell(const unsigned int x, const unsigned int y) const;

		void SetCell(GameObject* gameObject, const unsigned int index);
		void SetCell(GameObject* gameObject, const VPVector2 coordinates);
		void SetCell(GameObject* gameObject, const unsigned int x, const unsigned int y);

		void MoveCell(const VPVector2 startCoordinates, const VPVector2 targetCoordinates);
		void MoveCell(const unsigned startX, const unsigned startY, const unsigned targetX, const unsigned targetY);

	private:
		void DrawGrid();

		inline unsigned int GetCellIndex(const VPVector2 coordinates) const { return coordinates.x + coordinates.y * gridWidth; }
		inline unsigned int GetCellIndex(const unsigned int x, const unsigned int y) const { return x + y * gridWidth; }

		unsigned const int gridWidth  = 10;
		unsigned const int gridHeight = 20;

		std::vector<GameObject*> cells;

		bool drawGrid = true;
	};
}

