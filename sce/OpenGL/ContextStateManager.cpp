
#include <GL/glew.h>

#include "ContextStateManager.h"

namespace sce
{
	ContextStateManager* ContextStateManager::_instance = nullptr;

	ContextStateManager* ContextStateManager::getInstance()
	{
		if (!_instance)
		{
			_instance = new ContextStateManager();
		}

		return _instance;
	}

	ContextStateManager::ContextStateManager()
	{

	}

	void ContextStateManager::init(int width, int height)
	{
		glViewport(0, 0, width, height);

		glEnable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}
