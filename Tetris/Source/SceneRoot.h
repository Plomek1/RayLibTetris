#pragma once

#include "Component.h"

namespace Tetris 
{
	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, GameObject& root) : Component(game, root) { InitScene(); }
		
		void InitScene();
		void Update(float deltaTime) override {}
	};
}

