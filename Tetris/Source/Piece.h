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

		bool MovePiece(VPVector2 moveDifference = { 0, 1 });

		
		PieceType pieceType = I;

	private:
		PieceDefinition* definition = nullptr;
		TetrisGrid* grid;
		VPVector2 coordinates;
		std::vector<Block*> blocks;
	};
}

