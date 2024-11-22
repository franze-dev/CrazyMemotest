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

		while (window->isOpen())
		{
			Update();
			Draw();
		}

		Close();
	}

	void Load()
	{
		GeneralWindow::Init();
		Gameplay::Load();
	}

	void Init()
	{
		srand(static_cast <unsigned int>(time(0)));
		Gameplay::Init();
	}

	void Update()
	{
		while (window->pollEvent(GlobalEvent::event))
		{
			if (GlobalEvent::event.type == Event::Closed)
				window->close();
		}

		Gameplay::Update();
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


