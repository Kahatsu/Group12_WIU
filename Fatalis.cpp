#include "Fatalis.h"
#include "RandomNumGenerator.h"
#include <iostream>

Fatalis::Fatalis() : Enemy(20, 300, 300, "Fatalis", 100)
{}

void Fatalis::attack(Player * player)
{
	//get stronger if not below 2/3 health after 3 turns
	if (getBattlecounter() == 3 && getHealth() > (2/3*getMaxHealth())) {
		changeDamage(10);
	}

	RandomNumGenerator ranNum;
	
	// Existing burn damage
	player->takeDot(10);

	int randomNumber = ranNum.getRandomNum(1, 100);

	if (randomNumber <= 30) {
		special_attack(player);
	}
	else {
		player->takeDamage(getDamage());
	}

	changeBattlecounter(1);
}

void Fatalis::special_attack(Player * player)
{
	std::cout << "Fatalis burns you\n";
	player->changeDOTCounter(3);
}


