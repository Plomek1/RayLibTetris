#include "Game.h"

#include "GameObject.h"
#include "ShapeRenderer.h"
#include <raylib.h>
#include <initializer_list>

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(800, 800, "Tetris");
		SetTargetFPS(targetFps);

		//Test objects
		GameObject go1 = GameObject(Vector2(500, 300));
		GameObject go2 = GameObject(Vector2(200, 300));
		GameObject go3 = GameObject(Vector2(200, 700));
		go1.AddComponent<ShapeRenderer>(ShapeRenderer::CIRCLE, std::initializer_list<float>{15});
		go1.AddComponent<ShapeRenderer>(ShapeRenderer::SQUARE, std::initializer_list<float>{20}, YELLOW);
		go1.AddComponent<ShapeRenderer>(ShapeRenderer::RECTANGLE, std::initializer_list<float>{ 20, 10 }, RED);
		gameObjects.push_back(go1);
		gameObjects.push_back(go2);
		gameObjects.push_back(go3);
		

		GameLoop();
	}

	void Game::GameLoop()
	{
		while (!WindowShouldClose())
		{
			BeginDrawing();

			//Update
			float deltaTime = GetFrameTime();
			for (GameObject& go : gameObjects)
				go.Update(deltaTime);

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
