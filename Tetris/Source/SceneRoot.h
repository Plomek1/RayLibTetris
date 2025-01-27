#pragma once

#include "Component.h"

namespace Tetris 
{
	class TetrisGrid;

	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, GameObject& root) : Component(game, root) { InitScene(); }
		
		void InitScene();
		void Update(float deltaTime) override;

		std::weak_ptr<TetrisGrid> grid;
	};
}

