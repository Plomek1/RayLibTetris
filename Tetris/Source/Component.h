#pragma once

#include "GameObject.h"

namespace Tetris
{
	class Component : protected Object
	{
	public:
		GameObject& root;

		virtual void Update(const float deltaTime) abstract;

	protected:
		Component(Game& game, GameObject& root) : Object(game), root(root) {}
	};
}


