#include "Piece.h"

#include "Block.h"
#include "PieceDefinitions.h"

#include <iostream>

namespace Tetris
{
	void Piece::Start()
	{
		switch (pieceType)
		{
		case PieceType::I:
			definition = &pieceI;
			break;
		case PieceType::J:
			definition = &pieceJ;
			break;
		case PieceType::L:
			definition = &pieceL;
			break;
		case PieceType::O:
			definition = &pieceO;
			break;
		case PieceType::S:
			definition = &pieceS;
			break;
		case PieceType::T:
			definition = &pieceT;
			break;
		case PieceType::Z:
			definition = &pieceZ;
			break;
		}

		coordinates = VPVector2(coordinates.x + definition->spawnOffset.x, coordinates.y + definition->spawnOffset.y);
		for (VPVector2& blockPosition : definition->rotations[currentRotation])
		{
			VPVector2 initialCoordinates(coordinates.x + blockPosition.x, coordinates.y + blockPosition.y);
			blocks.push_back(Create("Block")->AddComponent<Block>(nullptr, grid, initialCoordinates, definition->color));
		}
	}

	bool Piece::Move(VPVector2 direction, bool lock)
	{
		bool moveValid = true;
		coordinates = VPVector2(coordinates.x + direction.x, coordinates.y + direction.y);
		for (Block* block : blocks)
		{
			if (!block->CheckMove(VPVector2(block->coordinates.x + direction.x, block->coordinates.y + direction.y)))
			{
				moveValid = false;
				break;
			}
		}

		if (moveValid)
		{
			for (Block* block : blocks)
				block->Move(VPVector2(block->coordinates.x + direction.x, block->coordinates.y + direction.y));
			return true;
		}
		
		if (lock)
		{
			for (Block* block : blocks)
				block->Lock();
		}

		return false;
	}

	void Piece::Rotate()
	{
		std::vector<VPVector2> blockPositions(blocks.size());
		bool rotationValid = true;
		int newRotation = (currentRotation + 1) % definition->rotationCount;

		for (size_t i = 0; i < blocks.size(); i++)
		{
			VPVector2& blockOffset = definition->rotations[newRotation][i];
			VPVector2 blockCoordinates(coordinates.x + blockOffset.x, coordinates.y + blockOffset.y);
			if (blocks[i]->CheckMove(blockCoordinates))
			{
				blockPositions[i] = blockCoordinates;
				continue;
			}

			rotationValid = false;
			break;
		}
		std::cout << "Rotating: " << rotationValid << std::endl;

		if (rotationValid)
		{
			for (size_t i = 0; i < blocks.size(); i++)
				blocks[i]->Move(blockPositions[i]);
			currentRotation = newRotation;
		}
	}
}

