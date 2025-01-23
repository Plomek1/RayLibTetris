#pragma once

#include <vector>
#include <memory>

namespace Tetris
{
	class GameObject;

	class Game
	{
	public:
		Game();
		~Game();

		void StartGame();
		void StopGame();

	private:
		void GameLoop();

		unsigned int targetFps = 60;
	
		std::vector<std::unique_ptr<GameObject>> gameObjects;
	};
}

