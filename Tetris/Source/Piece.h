#pragma once
#include "Component.h"

#include "vector"

namespace Tetris
{
	class Block;

	class Piece : public Component
	{
		Piece(Game& game, const uint32_t id, GameObject& root) : Component(game, id, root){}
	
	public:
		void Start() override;

		bool MovePiece();

		enum PieceType
		{
			I, J, L, O, S, T, Z
		};
		
		PieceType pieceType = I;

	private:
		std::vector<Block*> blocks;
	};
}

