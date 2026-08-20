#include "Player.h"
#include<iostream>

Player::Player():Entity(10,100,100,"placeholder")
{
    weight = 50;
    money = 10;
	x_coord = 17;
	y_coord = 33;
	interact = false;
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
		if ((map->checkMap(x_coord, y_coord - 1) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			y_coord -= 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 's':
		if ((map->checkMap(x_coord, y_coord + 1) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			y_coord += 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 'a':
		if ((map->checkMap(x_coord - 1, y_coord) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			x_coord -= 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 'd':
		if ((map->checkMap(x_coord + 1, y_coord) == 'o')) {
			map->updateMap('o', x_coord, y_coord);
			x_coord += 1;
			map->updateMap('P', x_coord, y_coord);
		}
		break;
	case 'f':
		std::cout << "pressed f\n";
		if ((map->checkMap(x_coord + 1, y_coord) == 'M') || (map->checkMap(x_coord - 1, y_coord) == 'M') || (map->checkMap(x_coord, y_coord + 1) == 'M') || (map->checkMap(x_coord, y_coord - 1) == 'M')) {
			interact = true;
			std::cout << "interacted\n";
		}
		break;
	default:
		map->updateMap('P', x_coord, y_coord);
		break;
	}
	
	map->setPlayerXCoord(x_coord);
	map->setPlayerYCoord(y_coord);
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

void Player::addConsumable(std::string item)
{
	inventory.addConsumable(item);
}

bool Player::getInteract()
{
	return interact;
}


void Player::setInteract()
{
	interact = false;
}
