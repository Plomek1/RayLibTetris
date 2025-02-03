#pragma once

#include "Component.h"
#include "Shapes.h"

#include <memory>
#include <concepts>

namespace Tetris
{
	template <typename T>
	concept ShapeType = std::is_base_of<Shape, T>::value;

	class ShapeRenderer : public Component
	{
	public:
		ShapeRenderer(Game& game, const uint32_t id, GameObject& root) : Component(game, id, root), shape(std::make_unique<Circle>()) {}

		template <ShapeType S>
		ShapeRenderer(Game& game, const uint32_t id, GameObject& root, S&& shape) : Component(game, id, root), shape(std::make_unique<S>(shape)) {}
		
		template <ShapeType S>
		inline S& GetShape() const
		{ return *static_cast<S*>(shape.get()); }
		
		template <ShapeType S, typename... Args>
		inline S& SetShape(Args&&... args) 
		{ 
			this->shape = std::make_unique<S>(std::forward<Args>(args)...); 
			return GetShape<S>();
		}

		inline void Update(const float deltaTime) override { shape->Draw(root.position); }

	private:
		std::unique_ptr<Shape> shape;
	};

}

