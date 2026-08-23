
#include "BobbyTheBandit.h"
#include<iostream>

BobbyTheBandit::BobbyTheBandit() :Enemy(10, 45, 45, "BobbyTheBandit", 20) {
	stolen = false;
	moneysteal = 5;
}

int BobbyTheBandit::getmoneysteal() {
	return moneysteal;
}

void BobbyTheBandit::attack(Player* player) {
	player->takeDamage(getDamage());
	
}

void BobbyTheBandit::special_attack(Player* player) {
	if (stolen) {
		return;
	}
	else {
		player->loseMoney(getmoneysteal());
		stolen = true;
	}
}
