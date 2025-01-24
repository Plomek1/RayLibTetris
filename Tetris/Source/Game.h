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

		template <typename... Args>
		inline GameObject& CreateGameObject(Args&&... args)
		{ 
			GameObject* go = new GameObject(*this, args...);
			gameObjects.push_back(std::unique_ptr<GameObject>(go));
			return *go;
		}

		void DestroyGameObject(GameObject& gameObject);

	private:
		void GameLoop();

		unsigned int targetFps = 60;
	
		std::vector<std::unique_ptr<GameObject>> gameObjects;
	};
}

