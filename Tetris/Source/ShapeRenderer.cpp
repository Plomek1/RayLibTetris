#include "ShapeRenderer.h"

#include <iostream>

namespace Tetris
{
	void ShapeRenderer::Update(const float deltaTime)
	{
		switch (shapeType)
		{
		case CIRCLE:
			DrawCircle(root.position.x, root.position.y, dimensions[0], color);
			break;

		case SQUARE:

			DrawRectangle(root.position.x, root.position.y, dimensions[0], dimensions[0], color);
			break;

		case RECTANGLE:
			DrawRectangle(root.position.x, root.position.y, dimensions[0], dimensions[1], color);
			break;
		}
	}
	ShapeRenderer::ShapeRenderer(GameObject& root) 
		: Component(root), shapeType(CIRCLE), dimensions(std::vector<float>{1}), color(WHITE) {}

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, float dimension) 
		: Component(root), shapeType(shapeType), dimensions(std::vector<float>{dimension})
	{ Init(dimensions); }

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, float dimension, Color color)
		: Component(root), shapeType(shapeType), dimensions(std::vector<float>{dimension}), color(color) 
	{ Init(dimensions); }

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, std::vector<float> dimensions) 
		: Component(root), shapeType(shapeType), color(WHITE) 
	{ Init(dimensions); }

	ShapeRenderer::ShapeRenderer(GameObject& root, ShapeType shapeType, std::vector<float> dimensions, Color color) 
		: Component(root), shapeType(shapeType), color(color) 
	{ Init(dimensions); }

	void ShapeRenderer::Init(std::vector<float>& dimensionsInput)
	{
		if (!ValidateDimensions(dimensionsInput))
		{
			std::cerr << "Wrong dimensions count used in ShapeRenderer";
			SetDefaultDimensions(dimensions);
			return;
		}
		dimensions = dimensionsInput;
	}

	bool ShapeRenderer::ValidateDimensions(std::vector<float>& dimensions)
	{
		switch (shapeType)
		{
		case CIRCLE:
			return dimensions.size() == 1;
		case SQUARE:
			return dimensions.size() == 1;
		case RECTANGLE:
			return dimensions.size() == 2;
		}
	}

	void ShapeRenderer::SetDefaultDimensions(std::vector<float>& dimensions)
	{
		switch (shapeType)
		{
		case CIRCLE:
			dimensions = { 1 };
			return;
		case SQUARE:
			dimensions = { 1 };
			return;
		case RECTANGLE:
			dimensions = { 1, 1 };
			return;
		}
	}

}

