#include "Player.h"

Player::Player():Entity(10,100,100,"placeholder")
{
    weight = 50;
    money = 10;
	x_coord = 2;
	y_coord = 4;
}

double Player::getWeight()
{
    return weight;
}   

double Player::reduceWeight(double minus)
{
    return weight - minus;
}

double Player::gainWeight(double add)
{
    return weight + add;
}

int Player::getMoney()
{
    return money;
}

void Player::gainMoney(int value)
{
    money += value;
}

void Player::loseMoney(int value)
{
    money -= value;
}

void Player::equip()
{

}


void Player::addWeapon(std::string weapon) {
	inventory.addWeapon(weapon);
}

void Player::addPotion(std::string potion) {
	inventory.addConsumable(potion, 1);
}


void Player::openInventory()
{
    inventory.displayInventoryUI();
}

void Player::pickUpItem()
{
    
}

void Player::move(char key, Map* map)
{
	switch (key) {
	case 'w':
		if (y_coord != 0 && (map->checkMap(x_coord, y_coord - 1) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			y_coord -= 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 's':
		if (y_coord != 9 && (map->checkMap(x_coord, y_coord + 1) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			y_coord += 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 'a':
		if (x_coord != 0 && (map->checkMap(x_coord - 1, y_coord) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			x_coord -= 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 'd':
		if (x_coord != 9 && (map->checkMap(x_coord + 1, y_coord) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			x_coord += 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	default:
		map->updateMap('P', x_coord, y_coord);
		break;
	}
}

int Player::getXcoord()
{
    return x_coord;
}

void Player::setXcoord(int new_pos)
{
    x_coord = new_pos;
}

int Player::getYcoord()
{
    return y_coord;
}

void Player::setYcoord(int new_pos)
{
    y_coord = new_pos;
}
