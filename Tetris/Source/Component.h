#pragma once

#include "GameObject.h"

namespace Tetris
{
	class Component
	{
	public:
		GameObject& GetRoot();

		virtual void Update(const float deltaTime) abstract;

	protected:
		Component(GameObject& root) : root(root) {}

	private:
		GameObject& root;
	};
}


