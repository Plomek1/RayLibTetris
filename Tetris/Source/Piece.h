#pragma once
#include "Component.h"

#include "vector"

namespace Tetris
{
	class Block;
	class TetrisGrid;
	struct PieceDefinition;

	class Piece : public Component
	{
	public:
		enum PieceType
		{
			I, J, L, O, S, T, Z, LAST
		};

		Piece(Game& game, const uint32_t id, GameObject& root, TetrisGrid* grid, VPVector2 coordinates, PieceType pieceType) 
			: Component(game, id, root), grid(grid), coordinates(coordinates), pieceType(pieceType) {}
	
		void Start() override;

		bool Move(VPVector2 direction, bool lock);
		bool Rotate(bool doWallKick = true);

		
		PieceType pieceType = I;

	private:
		void WallKick();

		PieceDefinition* definition = nullptr;
		TetrisGrid* grid;
		VPVector2 coordinates;
		std::vector<Block*> blocks;

		int currentRotation = 0;
	};
}

