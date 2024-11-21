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

		}

	}

	bool IsCardInSlots(int cardToFindId, Slots::Slot slots[], int currentId)
	{
		for (int i = 0; i < currentId; i++)
			if (slots[i].currentCard.id == cardToFindId)
				return true;

		return false;
	}

	void Load(Card::Card cards[], int totalCards)
	{
		string source;
		for (int i = 0; i < totalCards; i++)
		{
			source = "Tiles_" + (i + 1);
			cards[i] = Card::LoadCard(source);
		}
	}

	void Init(Card::Card cards[], int totalCards)
	{
		for (int i = 0; i < totalCards; i++)
		{
			int pairId = (i % 2 == 0) ? i + 1 : i - 1;
			Card::InitCard(cards[i], i, pairId);
		}
	}

	void Draw(Card::Card cards[])
	{

	}
}