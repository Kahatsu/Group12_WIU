
#include "BobbyTheBandit.h"
#include<iostream>
#include "textUtils.h"

BobbyTheBandit::BobbyTheBandit() :Enemy(10, 45, 45, "BobbyTheBandit", 20) {
	
}

void BobbyTheBandit::attack(Player* player) {
	if (getBattlecounter() == 0) {
		special_attack(player);
	}
	
	player->takeDamage(getDamage());
	changeBattlecounter(1);
	
}

void BobbyTheBandit::special_attack(Player* player) {
	player->loseMoney(10);
	std::cout << "BobbyTheBandit stole 10 gold from you\n";
	slowPrint("I weally need this for the candy stwore\n", 20);
}
