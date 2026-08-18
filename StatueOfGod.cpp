#include "StatueOfGod.h"
#include<iostream>


StatueOfGod::StatueOfGod() :Enemy(20, 200, 200, "Statue Of God", 50) {
	canBlockability = true;
}

void StatueOfGod::attack() {
	std::cout << "Statue Of God cause 20 damage" << std::endl;
}

void StatueOfGod::special_attack() {
}