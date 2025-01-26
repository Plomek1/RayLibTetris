#include "SceneRoot.h"

#include "ShapeRenderer.h"
#include "TetrisGrid.h"

#include <iostream>

namespace Tetris
{
	void SceneRoot::InitScene()
	{
		GameObject& tetrisGrid = Create("Grid");
		tetrisGrid.AddComponent<TetrisGrid>();
		
		GameObject& square = Create("Square", VPVector2{ 500, 300 });
		ShapeRenderer& renderer = square.AddComponent<ShapeRenderer>();
		Rectangle& rec = renderer.SetShape<Rectangle>(VPVector2{ 20, 50 }, YELLOW);
		rec.color = PINK;
	}
}