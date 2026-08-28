#include "Jonkler.h"
#include<iostream>
#include "RandomNumGenerator.h"
#include "textUtils.h"

Jonkler::Jonkler() : Enemy(6.7, 67, 67, "Jonkler", 15)
{
}

void Jonkler::attack(Player* player) {

	int percent{};
	RandomNumGenerator ranNum;
	percent = ranNum.getRandomNum(1, 100);

	if (percent < 7) {
		special_attack(player);
		changeBattlecounter(-getBattlecounter());
	}
	else {
		player->takeDamage(getDamage());
		slowPrint("*The Jonkler throws magic mushrooms at you*", 10);
	}

	changeBattlecounter(1);
}

void Jonkler::special_attack(Player* player) {
	slowPrint("Hey, you have something behind your ear..", 10);
	slowPrint("*The Jonkler pulls out a coin from behind your ear", 10);
	slowPrint("+1 Coin", 10);
	player->gainMoney(1);
}
