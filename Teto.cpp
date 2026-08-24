#include "Teto.h"
#include <iostream>
Teto::Teto() :Enemy(10, 300, 300, "Teto", 100) {

};

void Teto::attack(Player* Player)
{
	player->takedamage(getDamage());
	std::cout << "BAGUETTERANG" << std::endl;
};

void Teto::specialattack(Player* Player)
{
	player->takedamage(getDamage());
	std::cout << "Teto word of the day! Insta Kill!!" << std::endl;
	//shld occur after 7 rnds

}
