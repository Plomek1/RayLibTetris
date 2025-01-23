#pragma once

#include "Component.h"

#include <raylib.h>

namespace Tetris
{
	class ShapeRenderer : public Component
	{
	public:
		enum ShapeType
		{
			CIRCLE,
			SQUARE,
			RECTANGLE
		};
		//TODO: Add single float constructors
		ShapeRenderer(GameObject& root);
		ShapeRenderer(GameObject& root, ShapeType shapeType, std::vector<float> dimensions);
		ShapeRenderer(GameObject& root, ShapeType shapeType, std::vector<float> dimensions, Color color);

		void Update(const float deltaTime) override;

		ShapeType shapeType;
		Color color;

	private:
		bool ValidateDimensions(std::vector<float>& dimensions);
		void SetDefaultDimensions(std::vector<float>& dimensions);

		std::vector<float> dimensions;
	};

}

