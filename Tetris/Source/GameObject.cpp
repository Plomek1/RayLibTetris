#include "GameObject.h"

#include "Component.h"

namespace Tetris
{
	void GameObject::Update(const float deltaTime)
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Update(deltaTime);
	}

	GameObject::GameObject()  = default;
	GameObject::GameObject(Vector2 position) : position(position) {}
	GameObject::GameObject(float posX, float posY) : position(Vector2(posX, posY)) {}
	
	GameObject::~GameObject() = default;
}

