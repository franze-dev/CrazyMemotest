#pragma once
#include "objects/card.h"
#include "objects/slot.h"

namespace CardManager
{
	void OrganizeCards(Card::Card cards[], Slots::Slot slots[], int totalCards);
	void Load(Card::Card cards[], int totalCards);
	void Init(Card::Card cards[], int totalCards);
	//void Update();
	void Draw(Slots::Slot slots[], int totalCards);
}
