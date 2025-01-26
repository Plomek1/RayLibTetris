#pragma once
#include "Component.h"

namespace Tetris
{
	class TetrisGrid : public Component
	{
	public:
		TetrisGrid(Game& game, GameObject& root) : Component(game, root) {}
		void Update(float deltaTime) override;

	private:

		void DrawGrid();

		unsigned const short gridWidth  = 10;
		unsigned const short gridHeight = 20;

		bool drawGrid = true;
	};
}

