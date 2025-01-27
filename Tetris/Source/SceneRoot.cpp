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

		std::shared_ptr<GameObject> squareGo = Create("Square").lock();
		square = squareGo->AddComponent<Block>(grid, VPVector2(3, 0), YELLOW);
		//square.lock()->Move(VPVector2(2, 3));
	}

	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		if (timer <= 0)
		{
			square.lock()->MoveDown();
			timer = startTimer;
		}
	}
}