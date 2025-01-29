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

		bool Move(VPVector2 targetCoordinates);
		inline bool MoveDown() { return Move(VPVector2(coordinates.x, coordinates.y + 1)); }
		void Delete();

	private:
		TetrisGrid* grid;

		VPVector2 coordinates {0, 0} ;
		Color color = WHITE;
	};
}

