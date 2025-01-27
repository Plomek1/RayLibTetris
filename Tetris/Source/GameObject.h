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
		inline std::weak_ptr<C> AddComponent()
		{
			auto component = std::make_shared<C>(game, *this);
			std::weak_ptr<C> componentWeak = component;

			components.push_back(std::move(component));
			components.back()->Start();
			return componentWeak;
		}
		
		template <ComponentChild C, typename... Args>
		inline std::weak_ptr<C> AddComponent(Args&&... args) 
		{
			auto component = std::make_shared<C>(game, *this, std::forward<Args>(args)...);
			std::weak_ptr<C> componentWeak = component;

			components.push_back(std::move(component));
			components.back()->Start();
			return componentWeak;
		}

		void Start() override;
		void Update(float deltaTime) override;

		std::string name;
		VPVector2 position;

		GameObject(GameObject&& other) = default;

	private:
		GameObject(Game& game, const int id, const std::string& name);
		GameObject(Game& game, const int id, const std::string& name, const VPVector2 position);
		GameObject(Game& game, const int id, const std::string& name, const float posX, const float posY);

		GameObject(const GameObject&) = delete;

		unsigned const int id;
		std::vector<std::shared_ptr<Component>> components;

		friend class Game;
	};
}