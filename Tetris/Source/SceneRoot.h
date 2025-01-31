#pragma once

#include "Component.h"

namespace Tetris 
{
	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, const uint32_t id, GameObject& root) : Component(game, id, root) {}
		
		void Start() override;
		void Update(float deltaTime) override;

	private:
		void SpawnPiece();

		uint32_t gridGoID = 0;
		uint32_t gridID = 0;
		uint32_t activePieceGoID = 0;
		uint32_t activePieceID = 0;
		float startTimer = .1;
		float timer = startTimer;
	};
}

