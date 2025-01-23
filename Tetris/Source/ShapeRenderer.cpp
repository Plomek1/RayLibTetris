#include "ShapeRenderer.h"

#include <assert.h>

namespace Tetris
{
	void ShapeRenderer::Update(const float deltaTime)
	{
		switch (shapeType)
		{
		CIRCLE:
			DrawCircle(GetRoot().position.x, GetRoot().position.y, dimensions[0], color);
			break;

		SQUARE:
			DrawRectangle(GetRoot().position.x, GetRoot().position.y, dimensions[0], dimensions[0], color);
			break;

		RECTANGLE:
			DrawRectangle(GetRoot().position.x, GetRoot().position.y, dimensions[0], dimensions[1], color);
			break;
		}
	}
	ShapeRenderer::ShapeRenderer(GameObject& root) : Component(root), shapeType(CIRCLE), dimensions(std::vector<float>{1}), color(WHITE) {}

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, std::initializer_list<float> dimensions) : Component(root), shapeType(shapeType), color(WHITE)
	{
		if (ValidateValues(dimensions)) this->dimensions = dimensions;
		else assert("Wrong dimensions count used to create ShapeRenderer!");
	}

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, std::initializer_list<float> dimensions, Color color) : Component(root), shapeType(shapeType), color(color)
	{
		if (ValidateValues(dimensions)) this->dimensions = dimensions;
		else assert("Wrong dimensions count used to create ShapeRenderer!");
	}

	bool ShapeRenderer::ValidateValues(std::initializer_list<float>& values)
	{
		switch (shapeType)
		{
		CIRCLE:
			return values.size() != 1;
		SQUARE:
			return values.size() != 1;
		RECTANGLE:
			return values.size() != 2;
		}
	}
}

