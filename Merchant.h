#pragma once
#include "Player.h"
#include <string>

class Merchant
{
public:
   Merchant(Player* player);

    std::string getItem(int choice);
};