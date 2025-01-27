#include "SceneRoot.h"

#include "ShapeRenderer.h"
#include "TetrisGrid.h"
#include <iostream>

namespace Tetris
{
	void SceneRoot::InitScene()
	{
		std::shared_ptr<GameObject> tetrisGrid = Create("Grid").lock();
		grid = tetrisGrid->AddComponent<TetrisGrid>();
	}
		
	void SceneRoot::Update(float deltaTime)
	{
		TetrisGrid* p_grid = grid.lock().get();
		std::cout << p_grid->root.name << std::endl;
	}
}