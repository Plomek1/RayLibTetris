#pragma once
#include "Component.h"

#include "vector"

namespace Tetris
{
	class Block;
	class TetrisGrid;

	class Piece : public Component
	{
	public:
		Piece(Game& game, const uint32_t id, GameObject& root, TetrisGrid* grid, VPVector2 coordinates) 
			: Component(game, id, root), grid(grid), coordinates(coordinates) {}
	
		void Start() override;

		bool MovePiece(VPVector2 moveDifference = { 0, 1 });

		enum PieceType
		{
			I, J, L, O, S, T, Z
		};
		
		PieceType pieceType = I;

	private:
		TetrisGrid* grid;
		VPVector2 coordinates;
		std::vector<Block*> blocks;
	};
}

