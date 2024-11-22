#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>

using namespace sf;
using namespace std;

namespace Card
{
	struct Card
	{
		Texture backTexture;
		Texture frontTexture;
		Sprite sprite;
		int id;
		int pairId;
		bool guessed;
		bool flipped;
	};

	bool IsMouseOnCard(Card card);
	void LoadCard(Card& card, string textureDir);
	void InitCard(Card& card, int id, int pairId);
	void Update(Card& card);
	void Draw(Card card);
};

