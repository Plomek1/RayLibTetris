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

		GameObject& CreateGameObject();
		GameObject& CreateGameObject(std::string name);
		GameObject& CreateGameObject(VPVector2 position);
		GameObject& CreateGameObject(std::string name, VPVector2 position);

		void DestroyGameObject(GameObject& gameObject);

	private:
		void GameLoop();

		unsigned int targetFps = 60;
	
		std::vector<std::unique_ptr<GameObject>> gameObjects;
	};
}

