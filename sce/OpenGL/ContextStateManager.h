#pragma once

namespace sce
{
	class ContextStateManager
	{
	public:
		static ContextStateManager* getInstance();

	    void init(int width, int height);

	private:
		ContextStateManager();

	private:
		static ContextStateManager* _instance;
	};
}
