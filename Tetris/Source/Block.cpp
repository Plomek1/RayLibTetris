#include "Block.h"

#include "TetrisGrid.h"
#include "iostream"

namespace Tetris
{
	void Block::Start()
	{
		auto s_grid = grid.lock();
		root.AddComponent<ShapeRenderer>(Square(s_grid->cellSize, color));

		s_grid->SetCell(&root, coordinates);
		root.position = s_grid->GetCellWorldPosition(coordinates);
	}

	bool Block::Move(VPVector2 targetCoordinates)
	{
		if (auto s_grid = grid.lock())
		{
			if (!s_grid->MoveCell(coordinates, targetCoordinates)) return false;
			
			root.position = s_grid->GetCellWorldPosition(targetCoordinates);
			coordinates = targetCoordinates;
			std::cout << root.position.x << ", " << root.position.y << std::endl;
			return true;
		}
		return false;
	}
}
