#include "SceneRoot.h"

#include "Globals.h"
#include "TetrisGrid.h"
#include "Piece.h"

#include <cstdlib>
#include <ctime>
#include <raylib.h>

namespace Tetris
{
	Piece::PieceType nextPieceType = Piece::LAST;

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
			score++;
			timer = 0;
		}

		RenderGameplayText();
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
				SpawnPiece();
				
				int clearedLines = Get(gridGoID)->GetComponent<TetrisGrid>(gridID)->ClearFullLines();
				if (clearedLines > 0)
				{
					switch (clearedLines)
					{
					case 1:
						score += 100;
						break;
					case 2:
						score += 300;
						break;
					case 3:
						score += 500;
						break;
					case 4:
						score += 800;
						break;
					}

					combo++;

					if (combo > 1)
						score += combo * 50;
				}
				else
					combo = 0;
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

	void SceneRoot::RenderGameplayText()
	{
		std::string text = std::to_string(score);
		int fontSize = 20;

		int textSize = MeasureText(text.c_str(), fontSize);
		int posX = Globals::windowParameters.windowSize.x * .666 + (Globals::windowParameters.windowSize.x * .333 - textSize) * .5;

		DrawText(text.c_str(), posX, Globals::windowParameters.windowSize.y * .5, fontSize, WHITE);

		text = "Next piece:";
		fontSize = 20;

		textSize = MeasureText(text.c_str(), fontSize);
		posX = Globals::windowParameters.windowSize.x * .666 + (Globals::windowParameters.windowSize.x * .333 - textSize) * .5;

		DrawText(text.c_str(), posX, Globals::windowParameters.windowSize.y * .25, fontSize, WHITE);

		switch (nextPieceType)
		{
		case Tetris::Piece::I:
			text = "I";
			break;
		case Tetris::Piece::J:
			text = "J";
			break;
		case Tetris::Piece::L:
			text = "L";
			break;
		case Tetris::Piece::O:
			text = "O";
			break;
		case Tetris::Piece::S:
			text = "S";
			break;
		case Tetris::Piece::T:
			text = "T";
			break;
		case Tetris::Piece::Z:
			text = "Z";
			break;
		}

		fontSize = 35;

		textSize = MeasureText(text.c_str(), fontSize);
		posX = Globals::windowParameters.windowSize.x * .666 + (Globals::windowParameters.windowSize.x * .333 - textSize) * .5;

		DrawText(text.c_str(), posX, Globals::windowParameters.windowSize.y * .28, fontSize, WHITE);
	}
}