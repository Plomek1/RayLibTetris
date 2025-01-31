#include "Block.h"

#include "TetrisGrid.h"
#include "iostream"

namespace Tetris
{
	void Block::Start()
	{
		root.AddComponent<ShapeRenderer>(0, Square(grid->cellSize, color));
		root.position = grid->GetCellWorldPosition(coordinates);
	}

	bool Block::CheckMove(VPVector2 targetCoordinates)
	{
		if (!grid->IsInBounds(targetCoordinates)) return false;
		return !grid->GetCell(targetCoordinates);
	}

	void Block::Move(VPVector2 targetCoordinates)
	{
		root.position = grid->GetCellWorldPosition(targetCoordinates);
		coordinates = targetCoordinates;
	}

	void Block::Lock()
	{
		grid->SetCell(&root, coordinates);
		std::cout << "LOCK" << std::endl;
	}

	void Block::Delete()
	{
		grid->SetCell(nullptr, coordinates);
		Destroy(root);
	}
}
