#pragma once

#include "Entity.h"
#include <string>

class Player;

class Merchant : public Entity
{
public:
    Merchant();

    void openShop(Player* player);

    std::string getItem(int choice);
    int getPrice(int choice);
};