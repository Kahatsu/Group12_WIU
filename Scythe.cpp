#include "Scythe.h"
#include "Player.h"
#include <iostream>

Scythe::Scythe()
    : Weapons(5, "Scythe", 15)
{}

void Scythe::applyPassive(Player* player, double damageDealt)
{
    double healAmount = damageDealt * 0.20;
    player->changeHealth(healAmount);
    std::cout << "Healed 20% of dmg" << std::endl;
}