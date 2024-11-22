#pragma once
#include "objects/card.h"
#include "objects/slot.h"

namespace CardManager
{
	void OrganizeCards(Card::Card cards[], Slots::Slot slots[], int totalCards);
	bool AreTwoCardsFlipped(Slots::Slot slots[], int totalCards);
	bool CheckEqualCardsFlipped();
	void DeflippCards();

	void Load(Card::Card cards[], int totalCards);
	void Init(Card::Card cards[], int totalCards);
	void Update(Slots::Slot slots[], int totalCards);
	void Draw(Slots::Slot slots[], int totalCards);
}
