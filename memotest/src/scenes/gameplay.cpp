#include "gameplay.h"

#include "objects/slot.h"
#include "utils/card_manager.h"

namespace Gameplay
{
	static const int totalCards = 8;
	static Card::Card cards[totalCards];
	Slots::Slot slots[totalCards];

	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);
	}

	void Gameplay::Init()
	{
		Slots::Init(slots, totalCards);
		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);
	}

	void Gameplay::Update()
	{
		//Todo
	}

	void Gameplay::Draw()
	{
		//Ui
		CardManager::Draw(slots, totalCards);
	}

	void Gameplay::Unload()
	{
		//Texturas
	}
}


