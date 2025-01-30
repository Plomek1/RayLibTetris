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

		Piece* piece = Create("ActivePiece", &activePieceGoID)->AddComponent<Piece>(&activePieceID, grid, VPVector2(2, 0));
	}

	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		if (timer <= 0)
		{
			if (GameObject* pieceGo = Get(activePieceGoID))
			{
				Piece* piece = pieceGo->GetComponent<Piece>(activePieceID);
				if (!piece->MovePiece())
				{
					Destroy(piece->root.id);
				}
			}


			timer = startTimer;
		}
	}
}