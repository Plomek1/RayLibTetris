#pragma once

#include "GameObject.h"

#include <map>
#include <vector>
#include <memory>

namespace Tetris
{
	class Game
	{
	public:
		Game();
		~Game();

		void StartGame();
		void StopGame();

		GameObject* CreateGameObject(const std::string& name, uint32_t* gameObjectID, const VPVector2 position);
		GameObject* GetGameObject(uint32_t gameObjectID) const;
		GameObject* GetGameObject(const std::string& name) const;

		void DestroyGameObject(GameObject& gameObject);
		void DestroyGameObject(uint32_t gameObject);
		
	private:
		void GameLoop();
		void UpdateGlobals();
		void Cleanup();

		uint32_t targetFps = 60;
		uint32_t nextID = 0;
		std::map<uint32_t, std::unique_ptr<GameObject>> gameObjects;
		std::vector<uint32_t> objectsToClenup;
	};
}

