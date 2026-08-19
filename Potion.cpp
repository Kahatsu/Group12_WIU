#include "Potion.h"

Potion::Potion():Consumables(0,"Potion")
{
	healAmount = 20;
}

void Potion::useConsumable(Player* player)
{
	player->changeHealth(20);
}
