#include "StatueOfGod.h"
#include<iostream>


StatueOfGod::StatueOfGod() :Enemy(20, 200, 200, "Statue Of God", 50) {
	AbilityBlocked = -1;
}

void StatueOfGod::attack(Entity& player) {
	std::cout << "Statue Of God cause 20 damage" << std::endl;
}

void StatueOfGod::special_attack(Entity& player) {
}