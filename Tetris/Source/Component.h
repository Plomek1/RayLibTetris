#pragma once

#include "Object.h"
#include "GameObject.h"
namespace Tetris
{
	class GameObject;
	class Component : public Object
	{
	public:
		GameObject& root;
	protected:
		Component(Game& game, const uint32_t id, GameObject& root) : Object(game, id), root(root) {}
	};
}


