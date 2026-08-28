#include "ManaPotion.h"

ManaPotion::ManaPotion() :Consumables(0, "Mana Potion")
{
	healmanaAmount = 30;
}



void ManaPotion::useConsumable(Player* player)
{

	player->changeMana(healmanaAmount);

}