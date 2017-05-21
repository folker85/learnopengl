#pragma once

 // STD
#include <vector>

#include "SceneNode.h"

namespace sce
{
	 // Forward declarations
	class Mesh;
	class Renderer;

	class Scene
	{
	public:
		void render(Renderer* renderer);

		void addNode(Mesh* node);

	private:
		SceneNode* _root;
		std::vector<Mesh*> _nodes;
	};
}
