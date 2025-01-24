#include "Game.h"

#include <raylib.h>

#include "ShapeRenderer.h"

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(800, 800, "Tetris");
		SetTargetFPS(targetFps);

		GameObject& go1 = CreateGameObject();
		GameObject& go2 = CreateGameObject(500, 300);
		GameObject& go3 = CreateGameObject(VPVector2(50, 600));

		go1.AddComponent<ShapeRenderer>(ShapeRenderer::RECTANGLE, std::vector<float>{50, 10}, YELLOW);
		go2.AddComponent<ShapeRenderer>(ShapeRenderer::SQUARE, 20, BLUE);
		go3.AddComponent<ShapeRenderer>();


		//DestroyGameObject(go2);
		
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

	void Game::DestroyGameObject(GameObject& gameObject)
	{
		GameObject* targetObject = &gameObject;
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(),
			[targetObject](const std::unique_ptr<GameObject>& obj) {
				return obj.get() == targetObject;
			}), gameObjects.end());
	}

	Game::Game()  = default;
	Game::~Game() = default;
}
