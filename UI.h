#pragma once
#include "Chest.h"
#include "Map.h"
#include "Player.h"
#include "RandomNumGenerator.h"
#include "Merchant.h"
#include "niuLai.h"
#include "BattleUI.h"

class UI
{
private:
    Player* player;
    Map* map;
    BattleUI BUI;
    Enemy *enemy;
public:
    UI();
    
    void clearScreen();

    void showMap(Map& map, Player& player);
    void showInventory(Player& player);
    void showCombat(Player& player, Enemy& enemy);
    // void showOccurrence();
    void showMerchant(Player& player);
    void showChest(Player& player, Chest& chest);

    void run(Map& map, Player& player);

    void encounterEnemy();
};