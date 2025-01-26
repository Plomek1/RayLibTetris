#include "Game.h"

#include "Globals.h"
#include "SceneRoot.h"

#include <raylib.h>

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(600, 800, "Tetris");
		SetTargetFPS(targetFps);

		std::weak_ptr<GameObject> root = CreateGameObject("Root");

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

			//Update loop
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

	std::weak_ptr<GameObject> Game::CreateGameObject()
	{
		int id = gameObjects.size();
		std::string name = "Object " + std::to_string(id);
		return CreateGameObject(name, VPVector2(0, 0));
	}

	std::weak_ptr<GameObject> Game::CreateGameObject(std::string& name)
	{
		return CreateGameObject(name, VPVector2(0, 0));
	}

	std::weak_ptr<GameObject> Game::CreateGameObject(VPVector2 position)
	{
		int id = gameObjects.size();
		std::string name = "Object " + std::to_string(id);
		return CreateGameObject(name, position);
	}

	std::weak_ptr<GameObject> Game::CreateGameObject(std::string& name, VPVector2 position)
	{
		int id = gameObjects.size();
		GameObject go(*this, id, name, position);
		gameObjects.push_back(std::make_shared<GameObject>(go));
		std::weak_ptr<GameObject> goWeak = gameObjects.back();

		return goWeak;
	}

	#pragma endregion

	void Game::DestroyGameObject(GameObject& gameObject)
	{ gameObjects.erase(gameObjects.begin() + gameObject.id); }

	void Game::StopGame()
	{ CloseWindow(); }

	Game::Game()  = default;
	Game::~Game() = default;
}
