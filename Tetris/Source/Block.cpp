#include "Block.h"

#include "TetrisGrid.h"
#include "iostream"

namespace Tetris
{
	void Block::Start()
	{
		root.AddComponent<ShapeRenderer>(0, Square(grid->cellSize, color));

		grid->SetCell(&root, coordinates);
		root.position = grid->GetCellWorldPosition(coordinates);
	}

	bool Block::Move(VPVector2 targetCoordinates)
	{
		if (!grid->MoveCell(coordinates, targetCoordinates)) return false;
			
		root.position = grid->GetCellWorldPosition(targetCoordinates);
		coordinates = targetCoordinates;
		std::cout << root.position.x << ", " << root.position.y << std::endl;
		return true;
	}

	void Block::Delete()
	{
		grid->SetCell(nullptr, coordinates);
		Destroy(root);
	}
}
