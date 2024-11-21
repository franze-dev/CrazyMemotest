#include "game.h"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <ctime>

using namespace sf;

namespace Memotest
{
	static RenderWindow* window;
	Sprite cardSprite;

	static void Load();
	static void Init();
	static void Update();
	static void Draw();
	static void Unload();
	static void Close();
	
	
	void Memotest::Run()
	{
		Load();
		Init();

		do
		{
			Update();
			Draw();

		} while (true);

		Close();
	}

	void Load()
	{

	}

	void Init()
	{
		srand(time(0));
		window = new RenderWindow(VideoMode(800, 600), "Crazy Memotest");
	}

	void Update()
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window->close();
		}

	}

	void Draw()
	{
	
		window->display();
	}

	void Unload()
	{

	}

	void Close()
	{
		delete window;
		Unload();
	}

}


