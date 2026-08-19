#include "NiuLai.h"
#include<iostream>

NiuLai::NiuLai() :Enemy(25, 120, 120, "NiuLai", 20) {

}


void NiuLai::attack(Entity& player) {
	player.takeDamage(getDamage());
	std::cout << "Mamaaa" << std::endl;
}

void NiuLai::special_attack(Entity& player) {
	player.takeDamage(60);
	std::cout << "MY COMPUTTERRR" << std::endl;
}