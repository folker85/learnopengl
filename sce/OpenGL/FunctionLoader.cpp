
#include "FunctionLoader.h"

namespace sce
{
	int FunctionLoader::load()
	{
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			//std::cout << "Failed to initialize GLEW" << std::endl;
			return -1;
		}
		return 0;
	}
}
