#include "Piece.h"

#include "Block.h"

namespace Tetris
{
	void Piece::Start()
	{

	}

	bool Piece::MovePiece()
	{
		bool moveValid = true;
		for (Block* block : blocks)
		{
			if (!block->CheckMove(VPVector2(block->coordinates.x, block->coordinates.y + 1)))
			{
				moveValid = false;
				break;
			}

			if (moveValid)
			{
				for (Block* block : blocks)
					block->MoveDown();
				return true;
			}
			for (Block* block : blocks)
				block->Lock();
			return false;
		}

		return false;
	}
}

