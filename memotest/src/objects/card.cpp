#include "card.h"
#include <iostream>

using namespace std;

namespace Card
{
	Card LoadCard(string textureDir)
	{
		Card card{};

		card.texture.loadFromFile(textureDir.c_str());
		card.sprite.setTexture(card.texture);

		return card;
	}

	void InitCard(Card& card, int id, int pairId)
	{
		card.id = id;
		card.pairId = pairId;
		card.guessed = false;
		card.flipped = false;
	}

	void Draw()
	{

	}
}