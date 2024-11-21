#include "card.h"

#include "utils/window.h"

#include <iostream>

using namespace std;
using namespace GeneralWindow;

namespace Card
{
	void LoadCard(Card& card, string textureDir)
	{
		card.texture.loadFromFile(textureDir.c_str());
		card.sprite.setTexture(card.texture);
	}

	void InitCard(Card& card, int id, int pairId)
	{
		card.id = id;
		card.pairId = pairId;
		card.guessed = false;
		card.flipped = false;
	}

	void Draw(Card card)
	{
		window->draw(card.sprite);
	}
}