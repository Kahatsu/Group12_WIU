#include "CasperGhost.h"
#include "RandomNumGenerator.h"
#include<iostream>

CasperGhost::CasperGhost() :Enemy(10, 40, 40, "CasperGhost", 20) {

}

void CasperGhost::attack(Player* player) {
	RandomNumGenerator rannum;

	// 50% chance to use special attack
	if (rannum.getRandomNum(1, 100) <= 45)
	{
		special_attack(player);
	}
	else
	{
		player->takeDamage(getDamage());
		std::cout << "phantom penetration did 10 damage" << std::endl;
	}
}

void CasperGhost::special_attack(Player* player) {
	player->takeDamage(getDamage());
	changeDamage(10);
	std::cout << "Phantom Pressure, increases Casper's damage by 10" << std::endl;
}