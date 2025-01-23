#pragma once

#include "GameObject.h"

#include <vector>

namespace Tetris
{
	class Renderer
	{
	public:
		Renderer(std::vector<GameObject>& gameObjects) : gameObjects(gameObjects) {}

		void Render();

	private:
		std::vector<GameObject>& gameObjects;
	};
}