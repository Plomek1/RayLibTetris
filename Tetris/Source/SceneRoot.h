#pragma once

#include "Component.h"

namespace Tetris 
{
	class SceneRoot : public Component
	{
	public:
		void InitScene();
		void Update(float deltaTime) override {}

	private:
		SceneRoot(GameObject& root) : Component(root) { InitScene(); }
	
		friend class GameObject;
	};
}

