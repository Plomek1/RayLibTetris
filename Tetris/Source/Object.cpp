#include "Object.h"

#include "Game.h"
#include "GameObject.h"

namespace Tetris
{
	std::weak_ptr<GameObject> Object::Create() const
	{
		return game.CreateGameObject();
	}

	std::weak_ptr<GameObject> Object::Create(const std::string& name) const
	{
		return game.CreateGameObject(name);
	}

	std::weak_ptr<GameObject> Object::Create(VPVector2 position) const
	{
		return game.CreateGameObject(position);
	}

	std::weak_ptr<GameObject> Object::Create(const std::string& name, VPVector2 position) const
	{
		return game.CreateGameObject(name, position);
	}

	void Object::Destroy(GameObject& gameObject) const
	{
		game.DestroyGameObject(gameObject);
	}

	void Object::Destroy(std::weak_ptr<GameObject> gameObject) const
	{
		game.DestroyGameObject(gameObject);
	}
}