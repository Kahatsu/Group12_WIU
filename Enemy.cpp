#include <string>
#include "Enemy.h"

Enemy::Enemy(double damage, double health, double max_health, std::string name, int mtd)
	: Entity(damage, health, max_health, 50, 50, name) {
	moneyToDrop = mtd;
	battleCounter = 0;
}

int Enemy::getMoneyToDrop()
{
	return moneyToDrop;
}

int Enemy::getBattlecounter()
{
	return battleCounter;
}

void Enemy::changeBattlecounter(int value)
{
	battleCounter += value;
}

std::string Enemy::getEnemyVoiceLines()
{
	return enemyVoiceLines;
}
