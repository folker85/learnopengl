
 // STD
#include <exception>

#include "SceneNode.h"

namespace sce
{
	SceneNode::SceneNode()
	{
		
	}

	SceneNode::~SceneNode()
	{
		for (auto c : _children)
		{
			delete c;
		}
	}

	void SceneNode::attachToParent(SceneNode* parent)
	{
		if (!parent)
		{
			throw std::exception("Trying attach to nullptr parent!");
		}

		 // todo: If _parent alreary setuped ?
		_parent = parent;
		_parent->addChild(this);
	}

	void SceneNode::addChild(SceneNode* child)
	{
		// todo: what if already present ?
		_children.push_back(child);
	}
}
