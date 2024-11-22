#include "card_manager.h"

#include <iostream>
#include <ctime>

#include "objects/slot.h"

using namespace std;

namespace CardManager
{
	static Card::Card* flippedCards[2];

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

	bool AreTwoCardsFlipped(Slots::Slot slots[], int totalCards)
	{
		int cardsFlipped = 0;
		int index = 0;
		do
		{
			if (slots[index].currentCard.flipped && !slots[index].currentCard.guessed)
			{
				flippedCards[cardsFlipped] = &slots[index].currentCard;
				cardsFlipped++;
			}

			index++;
		} while (cardsFlipped < 2 && index < totalCards);

		return cardsFlipped == 2;
	}

	bool CheckEqualCardsFlipped()
	{		
		if (flippedCards[0]->id == flippedCards[1]->pairId)
		{
			flippedCards[0]->guessed = true;
			flippedCards[1]->guessed = true;

			return true;
		}
		return false;
	}

	void DeflippCards()
	{
		flippedCards[0]->flipped = false;
		flippedCards[1]->flipped = false;
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

	void Update(Slots::Slot slots[], int totalCards)
	{
		for (int i = 0; i < totalCards; i++)
			Card::Update(slots[i].currentCard);
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