#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>

using namespace sf;
using namespace std;

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
		bool flipped;
	};

	bool IsMouseOnCard(Card card);
	void LoadCard(Card& card, string textureDir);
	void InitCard(Card& card, int id, int pairId);
	void Draw(Card card);
};

