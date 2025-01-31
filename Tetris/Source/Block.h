#pragma once

#include "Component.h"
#include "Vector2.h"
#include "ShapeRenderer.h"

namespace Tetris
{
	class TetrisGrid;

	class Block : public Component
	{
	public:
		Block(Game& game, const uint32_t id, GameObject& root, TetrisGrid* grid, VPVector2 coordinates, Color color) 
			: Component(game, id, root), grid(grid), coordinates(coordinates), color(color) {}

		void Start() override;

		bool CheckMove(VPVector2 targetCoordinates);
		bool IsNextToWall();
		void Move(VPVector2 targetCoordinates);
		inline void MoveDown() { Move(VPVector2(coordinates.x, coordinates.y + 1)); }
		void Lock();
		void Delete();

		VPVector2 coordinates {0, 0} ;
	private:
		TetrisGrid* grid;
		Color color = WHITE;
	};
}

