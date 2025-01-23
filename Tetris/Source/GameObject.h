#pragma once

#include "Vector2.h"

#include <vector>
#include <memory>
#include <concepts>

namespace Tetris
{
	class Component;

	template <typename T>
	concept ComponentChild = std::is_base_of<Component, T>::value;

	class GameObject
	{
	public:
		GameObject();
		GameObject(Vector2 position);
		GameObject(float posX, float posY);
		~GameObject();

		template <ComponentChild C>
		inline void AddComponent() { components.push_back(std::make_unique<C>(*this)); }
		
		template <ComponentChild C, typename... Args>
		inline void AddComponent(Args... args) { 
			
			components.push_back(std::make_unique<C>(*this, args...)); 
		}

		virtual void Update(const float deltaTime);

		Vector2 position;

	private:
		GameObject(const GameObject&) = delete;

		std::vector<std::unique_ptr<Component>> components;
	};
}