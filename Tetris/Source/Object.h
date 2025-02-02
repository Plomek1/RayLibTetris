#pragma once

#include "Vector2.h"

#include <string>;

namespace Tetris
{
	class Game;
	class GameObject;

	class Object
	{
	public: 
		const uint32_t id;

	protected:
		Object(Game& game, uint32_t id) : game(game), id(id) {}
		GameObject* Create(const std::string& name = "", uint32_t * gameObjectID = nullptr, VPVector2 position = { 0, 0 }) const;

		GameObject* Get(uint32_t id);
		GameObject* Get(const std::string& name);

		void Destroy(GameObject& gameObject);
		void Destroy(uint32_t gameObjectID);

		virtual void Start() {}
		virtual void Update(const float deltaTime) {}
	
	private:
		Game& game;

		friend class Game;
		friend class GameObject;
	};
}

