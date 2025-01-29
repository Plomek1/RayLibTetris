#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Block.h"
#include "Piece.h"

#include <iostream>

namespace Tetris
{
	void SceneRoot::Start()
	{
		GameObject* tetrisGrid = Create("Grid", &gridGoID);
		TetrisGrid* grid = tetrisGrid->AddComponent<TetrisGrid>(&gridID, Globals::windowParameters.windowSize.y / 20);

		Create("ActivePiece", &squareIDS[0])->AddComponent<Block>(&blockIDS[0], grid, VPVector2(3, 0), YELLOW);


		Create("Square1", &squareIDS[0])->AddComponent<Block>(&blockIDS[0], grid, VPVector2(3, 0), YELLOW);
		Create("Square2", &squareIDS[1])->AddComponent<Block>(&blockIDS[1], grid, VPVector2(4, 2), YELLOW);
		Create("Square3", &squareIDS[2])->AddComponent<Block>(&blockIDS[2], grid, VPVector2(1, 4), YELLOW);
		
	}

	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		if (timer <= 0)
		{
			GameObject* square0 = Get(squareIDS[0]);
			GameObject* square1 = Get(squareIDS[1]);
			GameObject* square2 = Get(squareIDS[2]);

			Block* block0 = square0 ? square0->GetComponent<Block>(blockIDS[0]) : nullptr;
			Block* block1 = square1 ? square1->GetComponent<Block>(blockIDS[1]) : nullptr;
			Block* block2 = square2 ? square2->GetComponent<Block>(blockIDS[2]) : nullptr;

			if (block0 && !block0->MoveDown()) block0->Delete();
			if (block1 && !block1->MoveDown()) block1->Delete();
			if (block2 && !block2->MoveDown()) block2->Delete();

			timer = startTimer;
		}
	}
}