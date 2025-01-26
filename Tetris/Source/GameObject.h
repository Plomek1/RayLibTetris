#pragma once

#include "Object.h"

#include <vector>
#include <memory>
#include <concepts>

namespace Tetris
{
	class Game;
	class Component;

	template <typename T>
	concept ComponentChild = std::is_base_of<Component, T>::value;

	class GameObject : protected Object
	{
	public:
		template <ComponentChild C>
		inline C& AddComponent()
		{ 
			auto component = std::unique_ptr<Component>(new C(game, *this));
			components.push_back(std::move(component)); 
			return *static_cast<C*>(components.back().get());
		}
		
		template <ComponentChild C, typename... Args>
		inline C& AddComponent(Args&&... args) 
		{
			auto component = std::unique_ptr<Component>(new C(game, *this, args...));
			components.push_back(std::move(component));
			return *static_cast<C*>(components.back().get());
		}

		virtual void Update(const float deltaTime);

		std::string name;
		VPVector2 position;

	private:
		GameObject(Game& game, int id, std::string name);
		GameObject(Game& game, int id, std::string name, VPVector2 position);
		GameObject(Game& game, int id, std::string name, float posX, float posY);

		GameObject(const GameObject&) = delete;

		unsigned const int id;
		std::vector<std::unique_ptr<Component>> components;

		friend class Game;
	};
}