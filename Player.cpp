#include "Player.h"

Player::Player() :Entity(10, 100, 100, "placeholder")
{
    weight = 50;
    money = 10;
    x_coord = 2;
    y_coord = 4;
    steppedOnMerchant = false; // added by honghonghong 19/8/2026 9:56pm
    currentTile = 'o'; // added by honghonghong 19/8/2026 10:21pm
}

bool Player::getSteppedOnMerchant()
{
    return steppedOnMerchant;
}

char Player::getCurrentTile()
{
    return currentTile;
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

void Player::addConsumable(std::string item, int quantity)
{
    inventory.addConsumable(item, quantity);
}

void Player::addWeapon(std::string weap) {
    inventory.addWeapon(weap);
}
void Player::move(char key, Map* map)
{
    switch (key)
    {
    case 'w':
        if (y_coord != 0)
        {
            char destination = map->checkMap(x_coord, y_coord - 1);

            if (destination == 'o' || destination == 'M')
            {
                // Restore the tile the player was previously standing on
                map->updateMap(currentTile, x_coord, y_coord);

                // Remember the new tile
                currentTile = destination;

                if (destination == 'M')
                {
                    steppedOnMerchant = true;
                }
                else
                {
                    steppedOnMerchant = false;
                }

                y_coord -= 1;

                map->updateMap('P', x_coord, y_coord);
            }
        }
        break;

    case 's':
        if (y_coord != 9)
        {
            char destination = map->checkMap(x_coord, y_coord + 1);

            if (destination == 'o' || destination == 'M')
            {
                map->updateMap(currentTile, x_coord, y_coord);

                currentTile = destination;

                if (destination == 'M')
                {
                    steppedOnMerchant = true;
                }
                else
                {
                    steppedOnMerchant = false;
                }

                y_coord += 1;

                map->updateMap('P', x_coord, y_coord);
            }
        }
        break;

    case 'a':
        if (x_coord != 0)
        {
            char destination = map->checkMap(x_coord - 1, y_coord);

            if (destination == 'o' || destination == 'M')
            {
                map->updateMap(currentTile, x_coord, y_coord);

                currentTile = destination;

                if (destination == 'M')
                {
                    steppedOnMerchant = true;
                }
                else
                {
                    steppedOnMerchant = false;
                }

                x_coord -= 1;

                map->updateMap('P', x_coord, y_coord);
            }
        }
        break;

    case 'd':
        if (x_coord != 9)
        {
            char destination = map->checkMap(x_coord + 1, y_coord);

            if (destination == 'o' || destination == 'M')
            {
                map->updateMap(currentTile, x_coord, y_coord);

                currentTile = destination;

                if (destination == 'M')
                {
                    steppedOnMerchant = true;
                }
                else
                {
                    steppedOnMerchant = false;
                }

                x_coord += 1;

                map->updateMap('P', x_coord, y_coord);
            }
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