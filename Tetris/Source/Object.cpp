#include "Object.h"

#include "Game.h"
#include "GameObject.h"

namespace Tetris
{
	GameObject* Object::Create(const std::string& name, uint32_t* gameObjectID, VPVector2 position) const
	{ return game.CreateGameObject(name, gameObjectID, position); }

	GameObject* Object::Get(uint32_t id)
	{ return game.GetGameObject(id); }

	void Object::Destroy(GameObject& gameObject)
	{ game.DestroyGameObject(gameObject); }

	void Object::Destroy(uint32_t gameObjectID)
	{ game.DestroyGameObject(gameObjectID); }
}