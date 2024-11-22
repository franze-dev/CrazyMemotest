#include "gameplay.h"

#include "objects/slot.h"
#include "utils/card_manager.h"
#include "utils/window.h"

namespace Gameplay
{
	static sf::Clock clock = sf::Clock();

	static float deFlipTimer;
	static const float deFlipTime = 1.0f;

	static int cardsFlipped;
	static int cardsGuessed;

	static Texture backgroundTexture;
	static Sprite background;

	static const int totalCards = 8;
	static Card::Card cards[totalCards];
	static Slots::Slot slots[totalCards];

	static Font font;
	static Text winText;
	static Text replayText;

	static void InitTexts();

	static void CheckCardsGuessed(sf::Time deltaTime);

	static bool CheckVictory();

	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);

		backgroundTexture.loadFromFile("res/sprites/gameplay_background.png");
		background.setTexture(backgroundTexture);

		font.loadFromFile("res/fonts/Mogra-Regular.ttf");
	}

	void Gameplay::Init()
	{
		deFlipTimer = 0.0f;

		cardsFlipped = 0;
		cardsGuessed = 0;

		Slots::Init(slots, totalCards);

		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);

		float backgroundScale = 0.5f;
		background.setScale(backgroundScale, backgroundScale);

		InitTexts();
	}

	void Gameplay::Update()
	{
		sf::Time deltaTime = clock.restart();

		if (CardManager::AreTwoCardsFlipped(slots, totalCards))
			CheckCardsGuessed(deltaTime);
		else
			CardManager::Update(slots, totalCards);
	}

	void Gameplay::Draw()
	{
		//Ui
		GeneralWindow::window->draw(background);
		CardManager::Draw(slots, totalCards);

		if (CheckVictory())
		{
			GeneralWindow::window->draw(winText);
			GeneralWindow::window->draw(replayText);
		}
	}

	void InitTexts()
	{
		int bigFontSize = 70;
		int smallFontSize = 30;

		float screenWidth = static_cast <float> (GeneralWindow::window->getSize().x);
		float screenHeight = static_cast <float> (GeneralWindow::window->getSize().y);

		int yOffSet = 25;

		winText = Text("YOU WON, GIL", font, bigFontSize);
		winText.setOrigin(winText.getLocalBounds().width / 2, winText.getLocalBounds().height / 2);
		winText.setPosition
		(
			screenWidth / 2,
			screenHeight / 2 - yOffSet
		);
		winText.setFillColor(Color::Red);


		replayText = Text("Press space to play again", font, smallFontSize);
		replayText.setOrigin(replayText.getLocalBounds().width / 2, replayText.getLocalBounds().height / 2);
		replayText.setPosition
		(
			screenWidth / 2,
			screenHeight - yOffSet
		);
		replayText.setFillColor(Color::Black);
	}

	void CheckCardsGuessed(sf::Time deltaTime)
	{
		deFlipTimer += deltaTime.asSeconds();
		if (CardManager::CheckEqualCardsFlipped())
		{
			cardsGuessed += 2;
		}
		else
		{
			if (deFlipTimer >= deFlipTime)
			{
				CardManager::DeFlippCards();
				deFlipTimer = 0.0f;
			}
		}
	}

	bool CheckVictory()
	{
		return cardsGuessed == totalCards;
	}
}


