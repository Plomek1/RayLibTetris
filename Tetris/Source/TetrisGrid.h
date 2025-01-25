#pragma once
#include "Component.h"

namespace Tetris
{
	class TetrisGrid : public Component
	{
	public:

		void Update(float deltaTime) override;

	private:
		TetrisGrid(GameObject& root) : Component(root) {}

		void DrawGrid();

		unsigned const short gridWidth  = 10;
		unsigned const short gridHeight = 20;

		bool drawGrid = true;
	
		friend class GameObject;
	};
}

