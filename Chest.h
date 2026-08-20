#pragma once
#include "Potion.h"
#include "Weapons.h"
class Chest
{
	int money;
	std::string item;
	std::string weapon;
	bool opened;

public:
	

	int getamtofmoney();
	std::string getWeapon();
	std::string getItem();
	Chest();
	Chest(int m, std::string w, std::string i);

	void open(Player* player);


};

