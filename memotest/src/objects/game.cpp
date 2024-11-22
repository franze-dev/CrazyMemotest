#include "game.h"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "utils/window.h"
#include "utils/event.h"

#include "scenes/gameplay.h"

#include <ctime>

using namespace sf;
using namespace GeneralWindow;

namespace Memotest
{
	Sprite cardSprite;

	static void Load();
	static void Init();
	static void Update();
	static void Draw();
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
		Gameplay::Load();
	}

	void Init()
	{
		srand(static_cast <unsigned int>(time(0)));
		GeneralWindow::Init();
		Gameplay::Init();
	}

	void Update()
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Gameplay::Update();

		while (window->pollEvent(GlobalEvent::event))
		{
			// "close requested" event: we close the window
			if (GlobalEvent::event.type == Event::Closed)
				window->close();
		}

	}

	void Draw()
	{
		window->clear();
		Gameplay::Draw();
		window->display();
	}

	void Close()
	{
		GeneralWindow::Delete();
	}

}


