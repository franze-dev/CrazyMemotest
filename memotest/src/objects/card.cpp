#include "card.h"

#include "utils/window.h"

#include <iostream>

using namespace std;
using namespace GeneralWindow;

namespace Card
{
	bool IsMouseOnCard(Card card)
	{
		Vector2i mousePos = Mouse::getPosition(*window);

		Vector2f cardTopLeft = card.sprite.getGlobalBounds().getPosition();

		Vector2f cardTopRight = { card.sprite.getGlobalBounds().getPosition().x + card.sprite.getGlobalBounds().getSize().x ,
								  card.sprite.getGlobalBounds().getPosition().y};

		Vector2f cardBottomLeft = { card.sprite.getGlobalBounds().getPosition().x,
									 card.sprite.getGlobalBounds().getPosition().y + card.sprite.getGlobalBounds().getSize().y};


		if (mousePos.x > cardTopLeft.x &&
			mousePos.x < cardTopRight.x &&
			mousePos.y > cardTopLeft.y &&
			mousePos.y < cardBottomLeft.y)
		{
			return true;
		}
		return false;
	}

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