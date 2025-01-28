#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Block.h"

#include <iostream>

namespace Tetris
{
	void SceneRoot::Start()
	{
		std::shared_ptr<GameObject> tetrisGrid = Create("Grid").lock();
		grid = tetrisGrid->AddComponent<TetrisGrid>(Globals::windowParameters.windowSize.y / 20);

		square1 = Create("Square1").lock()->AddComponent<Block>(grid, VPVector2(3, 0), YELLOW);
		square2 = Create("Square2").lock()->AddComponent<Block>(grid, VPVector2(4, 2), YELLOW);
		square3 = Create("Square3").lock()->AddComponent<Block>(grid, VPVector2(1, 4), YELLOW);
	}

	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		if (timer <= 0)
		{
			if(auto p_square1 = square1.lock())
				if (!p_square1->MoveDown()) Destroy(p_square1->root);
			if (auto p_square2 = square2.lock())
				if (!p_square2->MoveDown()) Destroy(p_square2->root);
			if (auto p_square3 = square3.lock())
				if (!p_square3->MoveDown()) Destroy(p_square3->root);
			timer = startTimer;
		}
	}
}