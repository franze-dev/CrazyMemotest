#include "slot.h"

namespace Slots
{
	void Init(Slot slots[], int totalCards)
	{
		int baseX = 30;
		int baseY = 50;

		int width = 75;
		int height = 250;

		for (int i = 0; i < totalCards; i++)
		{
			if (i == totalCards / 2)
				baseY += (baseY + height);

			slots[i].isOccupied = false;
			slots[i].shape.setSize({ width, height });
			slots[i].shape.setPosition(baseX * i, baseY);
		}
	}
};