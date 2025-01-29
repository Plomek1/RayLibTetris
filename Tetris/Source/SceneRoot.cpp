#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Block.h"

#include <iostream>

namespace Tetris
{
	void SceneRoot::Start()
	{
		GameObject* tetrisGrid = Create("Grid", &gridGoID);
		TetrisGrid* grid = tetrisGrid->AddComponent<TetrisGrid>(&gridID, Globals::windowParameters.windowSize.y / 20);

		Create("Square1", &squareIDS[0])->AddComponent<Block>(&blockIDS[0], grid, VPVector2(3, 0), YELLOW);
		Create("Square2", &squareIDS[1])->AddComponent<Block>(&blockIDS[1], grid, VPVector2(4, 2), YELLOW);
		Create("Square3", &squareIDS[2])->AddComponent<Block>(&blockIDS[2], grid, VPVector2(1, 4), YELLOW);
	}

	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		if (timer <= 0)
		{
			GameObject* gridGo =  Get(gridGoID);

			Block* square0 = Get(squareIDS[0])->GetComponent<Block>(blockIDS[0]);
			Block* square1 = Get(squareIDS[1])->GetComponent<Block>(blockIDS[1]);
			Block* square2 = Get(squareIDS[2])->GetComponent<Block>(blockIDS[2]);

			if (square0 && !square0->MoveDown()) square0->Delete();
			if (square1 && !square1->MoveDown()) square1->Delete();
			if (square2 && !square2->MoveDown()) square2->Delete();

			timer = startTimer;
		}
	}
}