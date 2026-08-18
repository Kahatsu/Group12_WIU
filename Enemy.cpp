#include <string>
#include "Enemy.h"

Enemy::Enemy(double damage, double health, double max_health, std::string name, int mtd):Entity(damage,health,max_health,name){
	moneyToDrop = mtd;
}

int Enemy::getMoneyToDrop()
{
	return moneyToDrop;
}
