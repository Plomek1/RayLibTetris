#pragma once

#include "Component.h"

#include <raylib.h>
#include <vector>
#include <initializer_list>

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
		ShapeRenderer(GameObject& root);
		ShapeRenderer(GameObject& root, ShapeType shapeType, std::initializer_list<float> dimensions);
		ShapeRenderer(GameObject& root, ShapeType shapeType, std::initializer_list<float> dimensions, Color color);

		void Update(const float deltaTime) override;


		ShapeType shapeType;
		Color color;

	private:
		bool ValidateValues(std::initializer_list<float>& values);

		std::vector<float> dimensions;
	};

}

