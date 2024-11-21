#include "gameplay.h"

#include "objects/slot.h"

namespace Gameplay
{
	const int totalCards = 8;

	Slots::Slot slots[totalCards];

	void Gameplay::Load()
	{
		//texura
	}

	void Gameplay::Init()
	{
		//Cartas
		Slots::Init(slots, totalCards);
	}

	void Gameplay::Update()
	{
		//Todo
	}

	void Gameplay::Draw()
	{
		//Ui
		//Cards
	}

	void Gameplay::Unload()
	{
		//Texturas
	}
}


