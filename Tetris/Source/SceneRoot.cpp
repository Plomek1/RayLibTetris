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

	//TODO: Score, Next piece

	void SceneRoot::Start()
	{
		Create("Grid", &gridGoID)->AddComponent<TetrisGrid>(&gridID, Globals::windowParameters.windowSize.y / 20);
		SetTextLineSpacing(50);
	}

	void SceneRoot::Update(float deltaTime)
	{
		if(!gameRunning)
		{ 
			RenderMainText();

			if (IsKeyPressed(KEY_ENTER)) StartGame();
			return;
		}
		
		if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
			MovePiece(VPVector2(-1, 0), false);

		if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
			MovePiece(VPVector2(1, 0), false);

		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
			RotatePiece();

		startTimer = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN) ? .1 : .5;

		timer += deltaTime;
		if (timer >= startTimer)
		{
			MovePiece(VPVector2(0, 1), true);
			timer = 0;
		}

		score++;
	}

	void SceneRoot::StartGame()
	{
		srand(time(0));
		score = 0;
		Get(gridGoID)->GetComponent<TetrisGrid>(gridID)->ClearGrid();
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
		SpawnPiece();
		gameRunning = true;
	}

	void SceneRoot::GameOver()
	{
		std::cout << "GAME OVER\n";
		gameRunning = false;
	}

	void SceneRoot::MovePiece(VPVector2 direction, bool lock)
	{
		if (GameObject* pieceGo = Get(activePieceGoID))
		{
			Piece* piece = pieceGo->GetComponent<Piece>(activePieceID);
			if (!piece->Move(direction, lock) && lock)
			{
				Destroy(piece->root.id);
				Get(gridGoID)->GetComponent<TetrisGrid>(gridID)->ClearFullLines();
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

		Piece* piece = Create("ActivePiece", &activePieceGoID)->AddComponent<Piece>(&activePieceID, grid, VPVector2(3, 0), nextPieceType);
		nextPieceType = static_cast<Piece::PieceType>(rand() % Piece::LAST);
	}
	void SceneRoot::RenderMainText()
	{
		if (score)
		{
			std::string text = "Your score: " + std::to_string(score);
			int fontSize = 40;

			int textSize = MeasureText(text.c_str(), fontSize);
			int posX = (Globals::windowParameters.windowSize.x - textSize) * .5;

			DrawText(text.c_str(), posX, Globals::windowParameters.windowSize.y * .33, fontSize, WHITE);

			text = "Press ENTER to restart game";
			fontSize = 35;

			textSize = MeasureText(text.c_str(), fontSize);
			posX = (Globals::windowParameters.windowSize.x - textSize) * .5;

			DrawText(text.c_str(), posX, Globals::windowParameters.windowSize.y * .4, fontSize, WHITE);
		}
		else
		{
			const char* text = "Press ENTER to start game";
			int fontSize = 35;

			int textSize = MeasureText(text, fontSize);
			int posX = (Globals::windowParameters.windowSize.x - textSize) * .5;

			DrawText(text, posX, Globals::windowParameters.windowSize.y * .33, fontSize, WHITE);
		}
	}
}