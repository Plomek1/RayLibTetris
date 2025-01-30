#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Block.h"
#include "Piece.h"

#include <cstdlib>
#include <iostream>

namespace Tetris
{
	Piece::PieceType nextPieceType = Piece::LAST;

	void SceneRoot::Start()
	{
		Create("Grid", &gridGoID)->AddComponent<TetrisGrid>(&gridID, Globals::windowParameters.windowSize.y / 20);
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
		SpawnPiece();
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
					SpawnPiece();
				}
			}


			timer = startTimer;
		}
	}
	void SceneRoot::SpawnPiece()
	{
		TetrisGrid* grid = Get(gridGoID)->GetComponent<TetrisGrid>(gridID);

		Piece* piece = Create("ActivePiece", &activePieceGoID)->AddComponent<Piece>(&activePieceID, grid, VPVector2(2, 0), nextPieceType);
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
	}
}