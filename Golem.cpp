#include "Golem.h"
#include "randomNumGenerator.h"
#include <iostream>

Golem::Golem() :Enemy(15, 100, 100, "Golem", 25)
{}
void Golem::attack(Player* player)
{
	RandomNumGenerator rannum;
	if (rannum.getRandomNum(1, 100) < 20) {
		special_attack(player);
	}
	else {
		std::cout << "Golem punches you";
		player->takeDamage(getDamage());
	}
}

void Golem::special_attack(Player* player)
{
	std::cout << "Golem stuns you\n";
	player->setStun(true);
}


