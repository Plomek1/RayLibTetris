#include "Game.h"

#include <raylib.h>

#include "SceneRoot.h"

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(800, 800, "Tetris");
		SetTargetFPS(targetFps);

		CreateGameObject("Root").AddComponent<SceneRoot>();

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

	#pragma region CreateGameObject Overloads

	GameObject& Game::CreateGameObject()
	{
		int id = gameObjects.size();
		std::string name = "Object " + std::to_string(id);
		GameObject* go = new GameObject(*this, id, name, { 0, 0 });
		gameObjects.push_back(std::unique_ptr<GameObject>(go));
		
		return *go;
	}

	GameObject& Game::CreateGameObject(std::string name)
	{
		int id = gameObjects.size();
		GameObject* go = new GameObject(*this, id, name, { 0, 0 });
		gameObjects.push_back(std::unique_ptr<GameObject>(go));

		return *go;
	}

	GameObject& Game::CreateGameObject(VPVector2 position)
	{
		int id = gameObjects.size();
		std::string name = "Object " + std::to_string(id);
		GameObject* go = new GameObject(*this, id, name, position);
		gameObjects.push_back(std::unique_ptr<GameObject>(go));

		return *go;
	}

	GameObject& Game::CreateGameObject(std::string name, VPVector2 position)
	{
		int id = gameObjects.size();
		GameObject* go = new GameObject(*this, id, name, position);
		gameObjects.push_back(std::unique_ptr<GameObject>(go));

		return *go;
	}

	#pragma endregion

	void Game::DestroyGameObject(GameObject& gameObject)
	{ gameObjects.erase(gameObjects.begin() + gameObject.id); }

	void Game::StopGame()
	{ CloseWindow(); }

	Game::Game()  = default;
	Game::~Game() = default;
}
