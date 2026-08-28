#include "SmokeBomb.h"
#include <iostream>

SmokeBomb::SmokeBomb() : Consumables(0, "SmokeBomb")
{}

void SmokeBomb::useConsumable(Player* player)
{
    std::cout << "Smoke fills the area...\n";
    std::cout << "You escaped from the battle!\n";

    player->setEscaped(true);
}