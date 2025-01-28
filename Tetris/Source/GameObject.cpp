#include "GameObject.h"

#include "Game.h"
#include "Component.h"

namespace Tetris
{
	void GameObject::Start()
	{
		for (auto c : components) c->Start();
	}

	void GameObject::Update(const float deltaTime)
	{
		for (size_t i = 0; i < components.size(); i++) components[i]->Update(deltaTime);
	}

	GameObject::GameObject(Game& game, const std::string& name)
		: Object(game), name(name) {}
	
	GameObject::GameObject(Game& game, const std::string& name, const VPVector2 position)
		: Object(game), name(name), position(position) {}
	
	GameObject::GameObject(Game& game, const std::string& name, const float posX, const float posY)
		: Object(game), name(name), position(VPVector2(posX, posY)) {}
}

