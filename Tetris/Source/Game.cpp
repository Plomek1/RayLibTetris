#include "Game.h"

#include <raylib.h>

#include "Globals.h"
#include "SceneRoot.h"

#include <iostream>

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(600, 800, "Tetris");
		SetTargetFPS(targetFps);

		CreateGameObject("Root").AddComponent<SceneRoot>();

		GameLoop();
	}

	void Game::GameLoop()
	{
		Color bgColor = {20, 20, 20, 255};

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(bgColor);
			
			UpdateGlobals();

			//Update
			float deltaTime = GetFrameTime();
			for (size_t i = 0; i < gameObjects.size(); i++)
				gameObjects[i]->Update(deltaTime);

			EndDrawing();
		}
		

		StopGame();
	}

	void Game::UpdateGlobals()
	{
		VPVector2 windowSize = VPVector2{ (float)GetScreenWidth(), (float)GetScreenHeight() };
		VPVector2 mousePos = VPVector2{ GetMousePosition() };

		Globals::windowParameters.windowSize = windowSize;
		Globals::windowParameters.mousePos = mousePos;
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
