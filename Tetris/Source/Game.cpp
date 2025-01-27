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

		std::shared_ptr<GameObject> root = CreateGameObject("Root").lock();
		root->AddComponent<SceneRoot>();

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

	std::weak_ptr<GameObject> Game::CreateGameObject(const std::string& name)
	{
		return CreateGameObject(name, VPVector2(0, 0));
	}

	std::weak_ptr<GameObject> Game::CreateGameObject(const VPVector2 position)
	{
		int id = gameObjects.size();
		std::string name = "Object " + std::to_string(id);
		return CreateGameObject(name, position);
	}

	std::weak_ptr<GameObject> Game::CreateGameObject(const std::string& name, const VPVector2 position)
	{
		int id = gameObjects.size();
		GameObject go(*this, id, name, position);
		gameObjects.push_back(std::make_shared<GameObject>(std::move(go)));
		return gameObjects.back();
	}

	#pragma endregion

	void Game::DestroyGameObject(std::weak_ptr<GameObject> gameObject)
	{
		if (auto go = gameObject.lock())
		gameObjects.erase(gameObjects.begin() + go->id); 
	}

	void Game::StopGame()
	{ CloseWindow(); }

	Game::Game()  = default;
	Game::~Game() = default;
}
