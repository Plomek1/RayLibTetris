#pragma once

#include "Component.h"

namespace Tetris 
{
	class TetrisGrid;
	class Block;
	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, const uint32_t id, GameObject& root) : Component(game, id, root) {}
		
		void Start() override;
		void Update(float deltaTime) override;

	private:
		uint32_t gridGoID = 0;
		uint32_t activePieceGoID = 0;
		uint32_t activePieceID = 0;
		uint32_t gridID = 0;
		uint32_t squareIDS[3] = { 0, 0, 0 };
		uint32_t blockIDS[3] = { 0, 0, 0 };
		float startTimer = .5;
		float timer = startTimer;
	};
}

