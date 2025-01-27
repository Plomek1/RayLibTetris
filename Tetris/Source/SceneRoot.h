#pragma once

#include "Component.h"

namespace Tetris 
{
	class TetrisGrid;
	class Block;
	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, GameObject& root) : Component(game, root) {}
		
		void Start() override;
		void Update(float deltaTime) override;

	private:
		std::weak_ptr<TetrisGrid> grid;
		std::weak_ptr<Block> square;

		float startTimer = .5;
		float timer = startTimer;
	};
}

