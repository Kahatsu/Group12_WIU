#include<unordered_map>
#include<vector>
#include<string>

#pragma once
//Inventory keeps track of items only does not have ownership over anything
class Inventory{
private:
	std::unordered_map<std::string, int> items;
	std::vector<std::string> weapons;
	std::vector<std::string> armors;

public:
	Inventory();
	
	void addItem(std::string item, int quantity);
	void removeItem(std::string item, int quantity);

	void addWeapon(std::string weapon);
	void dropWeapon(std::string weapon);

	void addArmor(std::string armor);
	void dropArmor(std::string armor);

	void displayInventory();
};

