#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Piece.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>

namespace Tetris
{
	Piece::PieceType nextPieceType = Piece::LAST;

	void SceneRoot::Start()
	{
		srand(time(0));
		Create("Grid", &gridGoID)->AddComponent<TetrisGrid>(&gridID, Globals::windowParameters.windowSize.y / 20);
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
		SpawnPiece();
	}

	void SceneRoot::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
			MovePiece(VPVector2(-1, 0), false);

		if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
			MovePiece(VPVector2(1, 0), false);

		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
			RotatePiece();

		timer -= deltaTime;
		if (timer <= 0)
		{
			MovePiece(VPVector2(0, 1), true);
			timer = startTimer;
		}
	}

	void SceneRoot::MovePiece(VPVector2 direction, bool lock)
	{
		if (GameObject* pieceGo = Get(activePieceGoID))
		{
			Piece* piece = pieceGo->GetComponent<Piece>(activePieceID);
			if (!piece->Move(direction, lock) && lock)
			{
				Destroy(piece->root.id);
				SpawnPiece();
			}
		}
	}

	void SceneRoot::RotatePiece()
	{
		if (GameObject* pieceGo = Get(activePieceGoID))
		{
			Piece* piece = pieceGo->GetComponent<Piece>(activePieceID);
			piece->Rotate();
		}
	}

	void SceneRoot::SpawnPiece()
	{
		TetrisGrid* grid = Get(gridGoID)->GetComponent<TetrisGrid>(gridID);

		Piece* piece = Create("ActivePiece", &activePieceGoID)->AddComponent<Piece>(&activePieceID, grid, VPVector2(2, 0), nextPieceType);
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
	}
}