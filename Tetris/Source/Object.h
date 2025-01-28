#pragma once

#include "Vector2.h"

#include <memory>
#include <string>;

namespace Tetris
{
	class Game;
	class GameObject;

	class Object
	{
	protected:
		Object(Game& game) : game(game) {}

		std::weak_ptr<GameObject> Create() const;
		std::weak_ptr<GameObject> Create(const std::string& name) const;
		std::weak_ptr<GameObject> Create(VPVector2 position) const;
		std::weak_ptr<GameObject> Create(const std::string& name, VPVector2 position) const;

		void Destroy(GameObject& gameObject) const;
		void Destroy(std::weak_ptr<GameObject> gameObject) const;

		virtual void Start() {}
		virtual void Update(const float deltaTime) {}
	
	private:
		Game& game;

		friend class Game;
		friend class GameObject;
	};
}

