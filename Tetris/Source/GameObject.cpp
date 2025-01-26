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

	GameObject::GameObject(Game& game, int id, std::string name)
		: Object(game), id(id), name(name) {}
	
	GameObject::GameObject(Game& game, int id, std::string name, VPVector2 position) 
		: Object(game), id(id), name(name), position(position) {}
	
	GameObject::GameObject(Game& game, int id, std::string name, float posX, float posY) 
		: Object(game), id(id), name(name), position(VPVector2(posX, posY)) {}
}

