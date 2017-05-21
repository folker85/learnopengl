#pragma once

#include <vector>

namespace sce
{
	class SceneNode;
	typedef std::vector<SceneNode*> SceneNodes;

	class SceneNode
	{
	public:
		SceneNode();
		~SceneNode();

		void attachToParent(SceneNode* parent);
		void addChild(SceneNode* child);

	private:
		SceneNode* _parent;
		SceneNodes _children;
	};
}
