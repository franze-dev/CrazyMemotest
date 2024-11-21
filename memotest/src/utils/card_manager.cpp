#include "card_manager.h"

#include <iostream>
#include <ctime>

#include "objects/slot.h"

using namespace std;

namespace CardManager
{
	static bool IsCardInSlots(int cardToFindId, Slots::Slot slots[], int currentId);

	void OrganizeCards(Card::Card cards[], Slots::Slot slots[], int totalCards)
	{
		//Cards get organized into the slots

		int randomId = 0;
		bool isSlotCompleted = false;

		for (int i = 0; i < totalCards; i++)
		{
			isSlotCompleted = false;

			do
			{
				randomId = rand() % totalCards;

				if (!IsCardInSlots(randomId, slots, i))
				{
					slots[i].currentCard = cards[randomId];
					isSlotCompleted = true;
				}
				else
					isSlotCompleted = false;

			} while (!isSlotCompleted);

			slots[i].currentCard.sprite.setPosition(slots[i].shape.getPosition());
			slots[i].shape.setSize(slots[i].currentCard.sprite.getGlobalBounds().getSize());
		}

	}

	void Load(Card::Card cards[], int totalCards)
	{
		string source;
		int currentCard = 0;

		for (int i = 0; i < totalCards; i++)
		{
			if (i != 0 && i % 2 == 0)
				currentCard++;
			
			source = "res/sprites/cards/Tiles_" + to_string(currentCard + 1) + ".png";
			Card::LoadCard(cards[i], source);
		}


	}

	void Init(Card::Card cards[], int totalCards)
	{
		for (int i = 0; i < totalCards; i++)
		{
			int pairId = (i % 2 == 0) ? i + 1 : i - 1;
			Card::InitCard(cards[i], i, pairId);
			cards[i].sprite.setScale(0.2f, 0.2f);
		}
	}

	void Draw(Slots::Slot slots[], int totalCards)
	{
		for (int i = 0; i < totalCards; i++)
			Card::Draw(slots[i].currentCard);
	}


	bool IsCardInSlots(int cardToFindId, Slots::Slot slots[], int currentId)
	{
		for (int i = 0; i < currentId; i++)
			if (slots[i].currentCard.id == cardToFindId)
				return true;

		return false;
	}
}