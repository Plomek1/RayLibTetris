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

		UpdateGlobals();

		CreateGameObject("Root").lock()->AddComponent<SceneRoot>();

		GameLoop();
	}

	void Game::GameLoop()
	{
		Color bgColor = {20, 20, 20, 255};

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(bgColor);

			//Call Update
			float deltaTime = GetFrameTime();
			for (size_t i = 0; i < gameObjects.size(); i++) gameObjects[i]->Update(deltaTime);

			UpdateGlobals();

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


	std::weak_ptr<GameObject> Game::CreateGameObject(const std::string& name, const VPVector2 position)
	{
		GameObject go(*this, name, position);
		gameObjects.push_back(std::make_shared<GameObject>(std::move(go)));
		return gameObjects.back();
	}

	void Game::DestroyGameObject(GameObject& gameObject)
	{
		auto at = std::find_if(gameObjects.begin(), gameObjects.end(), [&gameObject](auto go) { return &gameObject == go.get();  });
		gameObjects.erase(at);
	}

	void Game::DestroyGameObject(std::weak_ptr<GameObject> gameObject)
	{
		if (auto p_gameObject = gameObject.lock())
		{
			auto at = std::find_if(gameObjects.begin(), gameObjects.end(), [p_gameObject](auto go) { return p_gameObject.get() == go.get();  });
			gameObjects.erase(at); 
		}
	}

	void Game::StopGame()
	{ CloseWindow(); }

	Game::Game()  = default;
	Game::~Game() = default;
}
