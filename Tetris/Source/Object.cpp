#include "Object.h"

#include "Game.h"
#include "GameObject.h"

namespace Tetris
{
	GameObject& Object::Create() const
	{
		return game.CreateGameObject();
	}

	GameObject& Object::Create(std::string name) const
	{
		return game.CreateGameObject(name);
	}

	GameObject& Object::Create(VPVector2 position) const
	{
		return game.CreateGameObject(position);
	}

	GameObject& Object::Create(std::string name, VPVector2 position) const
	{
		return game.CreateGameObject(name, position);
	}

	void Object::Destroy(GameObject& gameObject) const
	{
		game.DestroyGameObject(gameObject);
	}
}