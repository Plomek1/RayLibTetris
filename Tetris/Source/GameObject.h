#pragma once

#include "Vector2.h"

#include <string>
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

		std::string name;
		VPVector2 position;

		GameObject& Create() const;
		GameObject& Create(std::string name) const;
		GameObject& Create(VPVector2 position) const;
		GameObject& Create(std::string name, VPVector2 position) const;
		void Destroy(GameObject& gameObject) const;

	private:
		GameObject(Game& game, int id, std::string name);
		GameObject(Game& game, int id, std::string name, VPVector2 position);
		GameObject(Game& game, int id, std::string name, float posX, float posY);

		GameObject(const GameObject&) = delete;

		unsigned const int id;
		Game& game;

		std::vector<std::unique_ptr<Component>> components;

		friend class Game;
	};
}