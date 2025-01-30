#include "Piece.h"

#include "Block.h"
#include "PieceDefinitions.h"

namespace Tetris
{
	void Piece::Start()
	{
		switch (pieceType)
		{
		case PieceType::I:
			definition = &pieceI;
			break;
		}
		definition = &pieceI;

		for (VPVector2& blockPosition : definition->rotations[0])
		{
			VPVector2 initialCoordinates(coordinates.x + blockPosition.x + definition->spawnOffset.x, coordinates.y + blockPosition.y + definition->spawnOffset.y);
			blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, initialCoordinates, definition->color));
		}
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

