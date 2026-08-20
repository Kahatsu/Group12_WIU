#include<unordered_map>
#include<vector>
#include<array>
#include<string>
#include"Items.h"

#pragma once
//Inventory keeps track of items only does not have ownership over anything
class Inventory{
private:
	std::unordered_map<std::string, int> consumables;
	std::vector<std::string> weapons;
	std::vector<std::string> armors;
	
	std::array <std::string, 2> consumables_list;
	std::array <std::string, 11> weapons_list;
	std::array <std::string, 3> armors_list;

public:
	Inventory();
	
	void addItems(Items& item);
	
	void addConsumable(std::string item);
	void removeConsumable(std::string item);

	void addWeapon(std::string weapon);
	void dropWeapon(std::string weapon);

	void addArmor(std::string armor);
	void dropArmor(std::string armor);

	void clearConsole();
	void displayInventoryUI();
};

