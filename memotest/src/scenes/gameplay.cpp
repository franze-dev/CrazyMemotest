#include "gameplay.h"

#include "objects/slot.h"
#include "utils/card_manager.h"

namespace Gameplay
{
	static int cardsFlipped = 0;

	static const int totalCards = 8;
	static Card::Card cards[totalCards];
	static Slots::Slot slots[totalCards];


	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);
	}

	void Gameplay::Init()
	{
		cardsFlipped = 0;
		Slots::Init(slots, totalCards);
		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);
	}

	void Gameplay::Update()
	{
		CardManager::Update(slots, totalCards);
		if (CardManager::AreTwoCardsFlipped(slots, totalCards))
		{
			if (!CardManager::CheckEqualCardsFlipped())
			{	//Timer
				CardManager::DeflippCards();
			}
		}
	}

	void Gameplay::Draw()
	{
		//Ui
		CardManager::Draw(slots, totalCards);
	}

	void Gameplay::Unload()
	{
		
	}
}


