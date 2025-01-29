#include "GameObject.h"

#include "Game.h"
#include "Component.h"

namespace Tetris
{
	void GameObject::Start()
	{
		for (auto& componentPair : components) InitComponent(*componentPair.second);
	}

	void GameObject::Update(const float deltaTime)
	{
		for (auto& componentPair : components) componentPair.second->Update(deltaTime);
	}

	GameObject::GameObject(Game& game, const uint32_t id, const std::string& name)
		: Object(game, id), name(name) {}
	
	GameObject::GameObject(Game& game, const uint32_t id, const std::string& name, const VPVector2 position)
		: Object(game, id), name(name), position(position) {}
	
	GameObject::GameObject(Game& game, const uint32_t id, const std::string& name, const float posX, const float posY)
		: Object(game, id), name(name), position(VPVector2(posX, posY)) {}

	void GameObject::InitComponent(Component& component)
	{ component.Start(); }
}

