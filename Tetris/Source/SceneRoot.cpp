#include "SceneRoot.h"

#include "ShapeRenderer.h"

namespace Tetris
{
	void SceneRoot::InitScene()
	{
		GameObject& go1 = root.Create();
		GameObject& go2 = root.Create(VPVector2{500, 300});
		GameObject& go3 = root.Create(VPVector2{ 500, 600 });

		go1.AddComponent<ShapeRenderer>(ShapeRenderer::RECTANGLE, std::vector<float>{50, 10}, YELLOW);
		go2.AddComponent<ShapeRenderer>(ShapeRenderer::SQUARE, 20, BLUE);
		go3.AddComponent<ShapeRenderer>();
	}
}