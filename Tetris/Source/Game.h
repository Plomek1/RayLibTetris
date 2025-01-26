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

		std::weak_ptr<GameObject> CreateGameObject();
		std::weak_ptr<GameObject> CreateGameObject(std::string& name);
		std::weak_ptr<GameObject> CreateGameObject(VPVector2 position);
		std::weak_ptr<GameObject> CreateGameObject(std::string& name, VPVector2 position);

		void DestroyGameObject(GameObject& gameObject);
		
	private:
		void GameLoop();
		void UpdateGlobals();

		unsigned int targetFps = 60;
	
		std::vector<std::shared_ptr<GameObject>> gameObjects;
	};
}

