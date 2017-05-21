
#include <exception>

#include "sce.h"

namespace sce
{
	Renderer* init(int width, int height)
	{
		if (FunctionLoader::load() == -1)
		{
			throw std::exception("Fail to load OpenGL functions!");
		}

		ContextStateManager* context_state_manager = ContextStateManager::getInstance();
		context_state_manager->init(width, height);

		// todo: correct remove
		Renderer* renderer = new Renderer();

		return renderer;
	}
}
