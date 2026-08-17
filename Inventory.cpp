#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

#include "Inventory.h"

Inventory::Inventory(){
	weapons.reserve(9);
	armors.reserve(8);
}

void Inventory::addItem(std::string item, int quantity){
	items[item] += quantity;
}

void Inventory::removeItem(std::string item, int quantity){
	items[item] -= quantity;

	if (items[item] <= 0) {
		items.erase(item);
	}
}

void Inventory::addWeapon(std::string weapon){
	weapons.push_back(weapon);
}

void Inventory::dropWeapon(std::string weapon){
	auto it = std::find(weapons.begin(), weapons.end(), weapon);

	if (it != weapons.end()) {
		weapons.erase(it);
	}
}

void Inventory::addArmor(std::string armor){
	armors.push_back(armor);
}

void Inventory::dropArmor(std::string armor){
	auto it = std::find(armors.begin(), armors.end(), armor);

	if (it != armors.end()) {
		armors.erase(it);
	}
}

void Inventory::displayInventory(){
	std::cout << "1. Items  2. Weapons  3. Armors:  ";
	int choice{};
	std::cin >> choice;

	switch (choice) {
	case 1:
		for (auto& item : items) {
			std::cout << item.first << "  x" << item.second << "\n";
		}
		break;
	case 2:
		for (std::string weapon : weapons) {
			std::cout << weapon << "\n";
		}
		break;
	case 3:
		for (std::string armor : armors) {
			std::cout << armor << "\n";
		}
		break;
	default:
		break;
	}
}


