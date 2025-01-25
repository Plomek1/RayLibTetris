#include "GameObject.h"

#include "Game.h"
#include "Component.h"

namespace Tetris
{
	void GameObject::Update(const float deltaTime)
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Update(deltaTime);
	}

	GameObject& GameObject::Create() const
	{ return game.CreateGameObject(); }	
	
	GameObject& GameObject::Create(std::string name) const
	{ return game.CreateGameObject(name); }

	GameObject& GameObject::Create(VPVector2 position) const
	{ return game.CreateGameObject(position); }

	GameObject& GameObject::Create(std::string name, VPVector2 position) const
	{ return game.CreateGameObject(name, position); }

	void GameObject::Destroy(GameObject & gameObject) const
	{ game.DestroyGameObject(gameObject); }

	GameObject::GameObject(Game& game, int id, std::string name)
		: game(game), id(id), name(name) {}
	
	GameObject::GameObject(Game& game, int id, std::string name, VPVector2 position) 
		: game(game), id(id), name(name), position(position) {}
	
	GameObject::GameObject(Game& game, int id, std::string name, float posX, float posY) 
		: game(game), id(id), name(name), position(VPVector2(posX, posY)) {}
}

