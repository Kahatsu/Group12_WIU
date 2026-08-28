#include "Potion.h"

Potion::Potion() : Consumables(0, "Health Potion")
{
    healAmount = 50;
}

void Potion::useConsumable(Player* player)
{
    player->changeHealth(healAmount);
    if (player->getHealth() >  player->getMaxHealth()) {
        player->changeHealth(-(player->getHealth() - player->getMaxHealth()));
    }
}