#include "Game.h"

#include "Globals.h"
#include "SceneRoot.h"

#include <raylib.h>
#include <iostream>

namespace Tetris
{
	void Game::StartGame()
	{
		InitWindow(600, 800, "Tetris");
		SetTargetFPS(targetFps);

		UpdateGlobals();

		CreateGameObject("Root", nullptr, {0, 0})->AddComponent<SceneRoot>();

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
			for (auto& gameObjectPair : gameObjects) gameObjectPair.second->Update(deltaTime);

			UpdateGlobals();
			Cleanup();

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

	void Game::Cleanup()
	{
		for (uint32_t& objID : objectsToClenup) gameObjects.erase(objID);
		objectsToClenup.clear();
	}

	GameObject* Game::CreateGameObject(const std::string& name, uint32_t* gameObjectID, const VPVector2 position)
	{
		uint32_t id = nextID++;
		if (gameObjectID) *gameObjectID = id;

		if (name.length() > 1)
		{
			GameObject go(*this, id, name, position);
			auto p_go = std::make_unique<GameObject>(std::move(go));
			gameObjects[id] = std::move(p_go);
		}
		else
		{
			std::string generatedName = "GameObject " + std::to_string(id);
			GameObject go(*this, id, generatedName, position);
			auto p_go = std::make_unique<GameObject>(std::move(go));
			gameObjects[id] = std::move(p_go);
		}
		return gameObjects[id].get();
	}

	GameObject* Game::GetGameObject(uint32_t gameObjectID) const
	{
		auto it = gameObjects.find(gameObjectID);
		return (it != gameObjects.end()) ? it->second.get() : nullptr;
	}

	void Game::DestroyGameObject(GameObject& gameObject)
	{
		objectsToClenup.push_back(gameObject.id); 
	}

	void Game::DestroyGameObject(uint32_t gameObjectID)
	{
		objectsToClenup.push_back(gameObjectID);
	}

	void Game::StopGame()
	{ CloseWindow(); }

	Game::Game()  = default;
	Game::~Game() = default;
}
