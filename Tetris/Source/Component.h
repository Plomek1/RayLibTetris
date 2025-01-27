#pragma once

#include "GameObject.h"

namespace Tetris
{
	class Component : public Object
	{
	public:
		GameObject& root;
	protected:
		Component(Game& game, GameObject& root) : Object(game), root(root) {}
	};
}


