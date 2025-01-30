#include "Piece.h"

#include "Block.h"

namespace Tetris
{
	void Piece::Start()
	{
		blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, coordinates, YELLOW));
		blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, VPVector2(coordinates.x, coordinates.y + 1), YELLOW));
		blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, VPVector2(coordinates.x, coordinates.y + 2), YELLOW));
		blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, VPVector2(coordinates.x, coordinates.y + 3), YELLOW));
	}

	bool Piece::MovePiece(VPVector2 moveDifference)
	{
		bool moveValid = true;
		for (Block* block : blocks)
		{
			if (!block->CheckMove(VPVector2(block->coordinates.x + moveDifference.x, block->coordinates.y + moveDifference.y)))
			{
				moveValid = false;
				break;
			}
		}

		if (moveValid)
		{
			for (Block* block : blocks)
				block->Move(VPVector2(block->coordinates.x + moveDifference.x, block->coordinates.y + moveDifference.y));
			return true;
		}
		
		for (Block* block : blocks)
			block->Lock();
		return false;
	}
}

