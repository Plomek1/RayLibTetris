#pragma once

#include "Object.h"

#include <unordered_map>
#include <memory>
#include <concepts>

namespace Tetris
{
	class Game;
	class Component;

	template <typename T>
	concept ComponentChild = std::is_base_of<Component, T>::value;

	class GameObject : public Object
	{
	public:
		template <ComponentChild C>
		inline C* AddComponent(uint32_t* componentID = nullptr)
		{
			const uint32_t id = nextID + 1;
			if (componentID) *componentID = id;

			components[id] = std::make_unique<C>(game, id, *this);;
			InitComponent(*components[id]);
			return dynamic_cast<C*>(components[id].get());
		}
		
		template <ComponentChild C, typename... Args>
		inline C* AddComponent(uint32_t* componentID, Args&&... args)
		{
			const uint32_t id = nextID++;
			if (componentID) *componentID = id;

			components[id] = std::make_unique<C>(game, id, *this, std::forward<Args>(args)...);;
			InitComponent(*components[id]);
			return dynamic_cast<C*>(components[id].get());
		}

		template <ComponentChild C>
		inline C* GetComponent(uint32_t componentID)
		{
			auto it = components.find(componentID);
			return (it != components.end()) ? dynamic_cast<C*>(it->second.get()) : nullptr;
		}

		void Start() override;
		void Update(float deltaTime) override;

		std::string name;
		VPVector2 position;

		GameObject(GameObject&& other) = default;

	private:
		GameObject(Game& game, const uint32_t id, const std::string& name);
		GameObject(Game& game, const uint32_t id, const std::string& name, const VPVector2 position);
		GameObject(Game& game, const uint32_t id, const std::string& name, const float posX, const float posY);

		GameObject(const GameObject&) = delete;

		void InitComponent(Component& component);

		uint32_t nextID = 0;
		std::unordered_map<uint32_t, std::unique_ptr<Component>> components;

		friend class Game;
	};
}