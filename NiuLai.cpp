#include "NiuLai.h"
#include<iostream>

NiuLai::NiuLai() :Enemy(25, 120, 120, "NiuLai", 20) {

}


void NiuLai::attack() {
	std::cout << "NiuLai cause 25 damage" << std::endl;
	std::cout << "Mamaaa" << std::endl;
}

void NiuLai::special_attack() {
	std::cout << "NiuLai cause 60 damage" << std::endl;
	std::cout << "MY COMPUTTERRR" << std::endl;
}