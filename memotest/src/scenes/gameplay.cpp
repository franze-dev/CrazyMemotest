#include "gameplay.h"

#include "objects/slot.h"
#include "utils/card_manager.h"
#include "utils/window.h"

namespace Gameplay
{
	static int cardsFlipped = 0;

	static Texture backgroundTexture;
	static Sprite background;

	static const int totalCards = 8;
	static Card::Card cards[totalCards];
	static Slots::Slot slots[totalCards];


	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);
		backgroundTexture.loadFromFile("res/sprites/gameplay_background.png");
		background.setTexture(backgroundTexture);
	}

	void Gameplay::Init()
	{
		cardsFlipped = 0;
		Slots::Init(slots, totalCards);
		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);

		background.setScale(0.5f, 0.5f);
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
		GeneralWindow::window->draw(background);
		CardManager::Draw(slots, totalCards);
	}

	void Gameplay::Unload()
	{
		
	}
}


