#pragma once

#include "Vector2.h"

#include <vector>
#include <memory>
#include <concepts>

namespace Tetris
{
	class Game;
	class Component;

	template <typename T>
	concept ComponentChild = std::is_base_of<Component, T>::value;

	class GameObject
	{
	public:

		template <ComponentChild C>
		inline void AddComponent() 
		{ components.push_back(std::unique_ptr<Component>(new C(*this))); }
		
		template <ComponentChild C, typename... Args>
		inline void AddComponent(Args&&... args) 
		{ components.push_back(std::unique_ptr<Component>(new C(*this, args...))); }

		virtual void Update(const float deltaTime);

		VPVector2 position;

	private:
		//Add object management
		GameObject(Game& game);
		GameObject(Game& game, VPVector2 position);
		GameObject(Game& game, float posX, float posY);

		GameObject(const GameObject&) = delete;

		Game& game;

		std::vector<std::unique_ptr<Component>> components;

		friend class Game;
	};
}