#include "window.h"


namespace GeneralWindow
{
	RenderWindow* window;

	void Init()
	{
		window = new RenderWindow(VideoMode(800, 600), "Crazy Memotest");
	}

	void Delete()
	{
		delete window;
	}
}

