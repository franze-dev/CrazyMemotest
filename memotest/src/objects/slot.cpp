#include "slot.h"

namespace Slots
{
	void Init(Slot slots[], int totalCards)
	{
		float baseX = 45;
		float baseY = 50;

		float width = 150;
		float height = 250;

		float multiplier = 0;

		for (int i = 0; i < totalCards; i++)
		{
			if (i == totalCards / 2)
			{
				baseY += (baseY + height);
				multiplier = 0;
			}

			float x = baseX + baseX * multiplier + width * multiplier;

			slots[i].isOccupied = false;
			slots[i].shape.setSize({ width, height });
			slots[i].shape.setPosition(x, baseY);

			multiplier++;
		}
	}
};