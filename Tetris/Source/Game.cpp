#include "Game.h"

#include "GameObject.h"
#include <raylib.h>

#include "ShapeRenderer.h"

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(800, 800, "Tetris");
		SetTargetFPS(targetFps);

		gameObjects.push_back(std::make_unique<GameObject>(500, 300));
		gameObjects.push_back(std::make_unique<GameObject>(500, 600));
		gameObjects[0]->AddComponent<ShapeRenderer>(ShapeRenderer::RECTANGLE, std::vector<float>{50, 10}, YELLOW);
		gameObjects[1]->AddComponent<ShapeRenderer>();
		
		GameLoop();
	}

	void Game::GameLoop()
	{
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(DARKGRAY);

			//Update
			float deltaTime = GetFrameTime();
			for (size_t i = 0; i < gameObjects.size(); i++)
				gameObjects[i]->Update(deltaTime);
			

			EndDrawing();
		}
		
		StopGame();
	}

	void Game::StopGame()
	{
		CloseWindow();
	}

	Game::Game()  = default;
	Game::~Game() = default;
}
