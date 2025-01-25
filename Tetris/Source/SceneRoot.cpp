#include "SceneRoot.h"

#include "ShapeRenderer.h"
#include "TetrisGrid.h"

namespace Tetris
{
	void SceneRoot::InitScene()
	{
		GameObject& tetrisGrid = root.Create();
		tetrisGrid.AddComponent<TetrisGrid>();
	}
}