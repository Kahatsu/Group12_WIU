#pragma once
#include "Map.h"
#include "Player.h"

class UI
{
public:
    void clearScreen();

    void showMap(Map& map, Player& player);
    void showInventory();
    void showCombat();
    void showOccurrence();
    void showMerchant();

    void run(Map& map, Player& player);
};