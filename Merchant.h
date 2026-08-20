#pragma once
#include "Player.h"
#include <string>
#include "Entity.h"

class Merchant : public Entity
{
public:
   Merchant(Player* player);

    std::string getItem(int choice);
};