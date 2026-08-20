#pragma once
#include "Potion.h"
#include "Weapons.h"
class Chest
{
	int money;
	std::string potion;
	std::string weapon;
	bool opened;

public:
	

	int getamtofmoney();

	Chest(int m, std::string w, std::string p);

	void open(Player* player);

};

