#include "card.h"

#include "utils/window.h"
#include "utils/event.h"

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

	bool IsCardFlipped(Card card)
	{
		if (IsMouseOnCard(card) && !card.flipped)
			if (GlobalEvent::event.type == Event::MouseButtonReleased)
			{
				card.flipped = true;
				return true;
			}

		return false;
	}

	void LoadCard(Card& card, string textureDir)
	{
		card.frontTexture.loadFromFile(textureDir.c_str());
		card.backTexture.loadFromFile("res/sprites/Backside.png");
		card.sprite.setTexture(card.backTexture);
	}

	void InitCard(Card& card, int id, int pairId)
	{
		card.id = id;
		card.pairId = pairId;
		card.guessed = false;
		card.flipped = false;
	}

	void Update(Card& card)
	{
		if (IsCardFlipped(card))
			card.flipped = true;

		if (card.flipped)
			card.sprite.setTexture(card.frontTexture);
		else
			card.sprite.setTexture(card.backTexture);
	}

	void Draw(Card card)
	{
		window->draw(card.sprite);
	}
}