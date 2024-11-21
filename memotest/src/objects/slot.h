#pragma once
#include "SFML/Graphics.hpp"

#include "card.h"

using namespace sf;

namespace Slots
{
	struct Slot
	{
		bool isOccupied;
		RectangleShape shape;
		Card::Card currentCard;
	};

	void Init(Slot slots[], int totalCards);
};

