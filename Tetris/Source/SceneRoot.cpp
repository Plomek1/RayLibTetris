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
		
		GameObject& sq = Create("Square", VPVector2{ 500, 300 });
		square = &sq;
		Rectangle rec = Rectangle(VPVector2{ 200, 300 }, YELLOW);
		std::weak_ptr<ShapeRenderer> wRenderer = sq.AddComponent<ShapeRenderer>(std::move(rec));
		if(auto renderer = wRenderer.lock())
			renderer->SetShape<Rectangle>(VPVector2{ 20, 50 }, PINK);
	}
	void SceneRoot::Update(float deltaTime)
	{
		timer -= deltaTime;
		std::cout << timer;
		if (timer <= 0)
		{
			Destroy(*square);
		}
	}
}