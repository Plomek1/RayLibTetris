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
		~GameObject();

		template <ComponentChild T, typename... Args>
		void AddComponent(Args... args);

		virtual void Update(const float deltaTime);

		Vector2 position;

	private:
		std::vector<std::unique_ptr<Component>> components;
	};
}