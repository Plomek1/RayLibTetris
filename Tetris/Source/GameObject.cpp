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

	GameObject::GameObject(Game& game) : game(game) {}
	GameObject::GameObject(Game& game, VPVector2 position) : game(game), position(position) {}
	GameObject::GameObject(Game& game, float posX, float posY) : game(game), position(VPVector2(posX, posY)) {}
}

