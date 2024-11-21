#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

namespace Card
{
	/*Texture cardTexture;
	cardTexture.loadFromFile("res/sprites/Backside.png");
	cardSprite = Sprite(cardTexture);
	cardSprite.setScale(0.2f, 0.2f);
	window->draw(cardSprite);*/

	struct Card
	{
		Texture texture;
		Sprite sprite;
		int id;
		int pairId;
		bool guessed;
	};

	void Load(Card cards[], int totalCards);
	void Init(Card cards[], int totalCards);
};

