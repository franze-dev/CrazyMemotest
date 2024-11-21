#include "card.h"
#include <iostream>

using namespace std;

namespace Card
{
	void Load(Card cards[], int totalCards)
	{
		string source;
		for (int i = 0; i < totalCards; i++)
		{
			source = "Tiles_" + (i + 1);
			cards[i].texture.loadFromFile(source.c_str());
			cards[i].sprite.setTexture(cards[i].texture);
		}
	}

	void Init(Card cards[], int totalCards)
	{
		for (int i = 0; i < totalCards; i++)
		{
			cards[i].id = i;
			cards[i].pairId = (i % 2 == 0) ? i + 1 : i - 1;
			cards[i].guessed = false;
		}
	}
}