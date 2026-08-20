#pragma once
#include "Chest.h"
#include "Map.h"
#include "Player.h"
#include "Merchant.h"

class UI
{
public:
    void clearScreen();

    void showMap(Map& map, Player& player);
    void showInventory(Player& player);
    // void showCombat();
    // void showOccurrence();
    void showMerchant(Player& player);
    void showChest(Player& player, Chest& chest);

    void run(Map& map, Player& player);
};