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


	//static void CheckVictory();

	void Gameplay::Load()
	{
		CardManager::Load(cards, totalCards);
		backgroundTexture.loadFromFile("res/sprites/gameplay_background.png");
		background.setTexture(backgroundTexture);
	}

	void Gameplay::Init()
	{
		deFlipTimer = 0.0f;

		cardsFlipped = 0;
		cardsGuessed = 0;

		Slots::Init(slots, totalCards);

		CardManager::Init(cards, totalCards);
		CardManager::OrganizeCards(cards, slots, totalCards);

		background.setScale(0.5f, 0.5f);
	}

	void Gameplay::Update()
	{
		sf::Time deltaTime = clock.restart();

		CardManager::Update(slots, totalCards);

		if (CardManager::AreTwoCardsFlipped(slots, totalCards))
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

		cout << deFlipTimer << endl;
		//clock.restart();
	}

	void Gameplay::Draw()
	{
		//Ui
		GeneralWindow::window->draw(background);
		CardManager::Draw(slots, totalCards);
	}

	void Gameplay::Unload()
	{

	}


	
}


