#pragma once

#include "GameObject.h"

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

		inline std::weak_ptr<GameObject> CreateGameObject() { return CreateGameObject("GameObject", VPVector2(0, 0)); }
		inline std::weak_ptr<GameObject> CreateGameObject(const std::string& name) { return CreateGameObject(name, VPVector2(0, 0)); }
		inline std::weak_ptr<GameObject> CreateGameObject(const VPVector2 position) { return CreateGameObject("GameObject", position); }
			   std::weak_ptr<GameObject> CreateGameObject(const std::string& name, const VPVector2 position);

		void DestroyGameObject(GameObject& gameObject);
		void DestroyGameObject(std::weak_ptr<GameObject> gameObject);
		
	private:
		void GameLoop();
		void UpdateGlobals();

		unsigned int targetFps = 60;
	
		std::vector<std::shared_ptr<GameObject>> gameObjects;
	};
}

