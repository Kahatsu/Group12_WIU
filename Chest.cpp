#include "Chest.h"

int Chest::getamtofmoney() {
	return money;
}



Chest::Chest(int m, std::string w, std::string p) {
	money = m;
	weapon = w;
	potion = p;
	opened = false;
	
}


void Chest::open(Player* player)
{
    if(opened) {
        return;
    }

    player->gainMoney(money);

    if(weapon != "") {
        player->addWeapon(weapon);
    }
    if(potion != "") {
        player->addConsumable(potion);
    }
    opened = true;
}
