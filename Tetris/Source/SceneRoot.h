#pragma once

#include "Component.h"

namespace Tetris 
{
	class SceneRoot : public Component
	{
	public:
		SceneRoot(Game& game, const uint32_t id, GameObject& root) : Component(game, id, root) {}
		
		void StartGame();
		void GameOver();

		void Start() override;
		void Update(float deltaTime) override;

	private:
		void MovePiece(VPVector2 direction, bool lock);
		void RotatePiece();
		void SpawnPiece();

		bool gameRunning = false;

		uint32_t gridGoID = 0;
		uint32_t gridID = 0;
		uint32_t activePieceGoID = 0;
		uint32_t activePieceID = 0;
		float startTimer = .3;
		float timer = 0;
	};
}

