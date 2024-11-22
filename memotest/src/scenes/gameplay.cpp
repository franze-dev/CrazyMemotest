#include "gameplay.h"

#include "SFML/Audio.hpp"

#include "objects/slot.h"
#include "utils/card_manager.h"
#include "utils/window.h"
#include "utils/event.h"

namespace Gameplay
{
	static sf::Clock clock = sf::Clock();

	static float deFlipTimer;
	static const float deFlipTime = 0.5f;

	static sf::Clock muteClock = sf::Clock();
	static float muteTimer;
	static float muteTime = 0.1f;

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
	static Text muteText;

	static Music music;

	static void InitTexts();
	static void CheckCardsGuessed(sf::Time deltaTime);
	static bool CheckVictory();
	static void Reset();
	static void SwitchMute();


	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);

		backgroundTexture.loadFromFile("res/sprites/gameplay_background.png");
		background.setTexture(backgroundTexture);

		font.loadFromFile("res/fonts/Mogra-Regular.ttf");
		music.openFromFile("res/music/Carnage-of-the-Cosmos.ogg");			
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

		music.setLoop(true);
		music.play();

		InitTexts();
	}

	void Gameplay::Update()
	{
		sf::Time deltaTime = clock.restart();

		muteTimer += deltaTime.asSeconds();

		if (CardManager::AreTwoCardsFlipped(slots, totalCards))
			CheckCardsGuessed(deltaTime);
		else
			CardManager::Update(slots, totalCards);

		if (Keyboard::isKeyPressed(Keyboard::Space))
			Reset();

		if (Keyboard::isKeyPressed(Keyboard::M) && muteTimer >= muteTime)
			SwitchMute();
	}

	void Gameplay::Draw()
	{
		//Ui
		GeneralWindow::window->draw(background);
		CardManager::Draw(slots, totalCards);

		GeneralWindow::window->draw(muteText);
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
		int tinyFontSize = 20;

		float screenWidth = static_cast <float> (GeneralWindow::window->getSize().x);
		float screenHeight = static_cast <float> (GeneralWindow::window->getSize().y);

		float yOffSet = 25;

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
		muteText.setFillColor(Color::Black);

		muteText = Text("M to mute sound", font, tinyFontSize);
		muteText.setPosition
		(
			yOffSet,
			yOffSet / 2
		);
		muteText.setFillColor(Color::Black);

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

	void Reset()
	{
		deFlipTimer = 0.0f;

		cardsFlipped = 0;
		cardsGuessed = 0;

		Slots::Init(slots, totalCards);

		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);
	}


	void SwitchMute()
	{
		if (music.getVolume() != 0.0f)
			music.setVolume(0.0f);
		else
			music.setVolume(100.0f);

		muteTimer = 0.0f;
	}
}


