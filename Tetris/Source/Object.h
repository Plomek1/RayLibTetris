#pragma once

#include "Vector2.h"

#include <string>;

namespace Tetris
{
	class Game;
	class GameObject;

	class Object
	{
	protected:
		Object(Game& game) : game(game) {}

		GameObject& Create() const;
		GameObject& Create(std::string name) const;
		GameObject& Create(VPVector2 position) const;
		GameObject& Create(std::string name, VPVector2 position) const;

		void Destroy(GameObject& gameObject) const;
	
	private:
		Game& game;

		friend class Game;
		friend class GameObject;
	};
}

