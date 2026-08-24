#include "Miku.h"
Miku::Miku() :Enemy(3737, 400, 400, "Miku")
{

};

void Teto::specialattack(Player* Player)
{
	player->takedamage(getDamage());
	std::cout << "Ready?! One! Two! Three! Miku Miku BEAMMMMMM" << std::endl;
	//should occur after 2 rnds
}
