#include "GameObject.h"
#include "Component.h"

namespace Tetris
{
	void GameObject::Update(const float deltaTime)
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Update(deltaTime);
	}

	template<ComponentChild T, typename... Args>
	void GameObject::AddComponent(Args... args)
	{
		components.push_back(std::make_unique<T>(*this, std::forward<Args>(args)...));
	}

	GameObject::GameObject()  = default;
	GameObject::GameObject(Vector2 position) : position(position) {};
	GameObject::~GameObject() = default;
}

