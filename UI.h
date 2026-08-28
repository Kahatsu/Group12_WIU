#pragma once
#include "Chest.h"
#include "Map.h"
#include "Player.h"
#include "RandomNumGenerator.h"
#include "Merchant.h"
#include "niuLai.h"
#include "BattleUI.h"
#include "Event.h"
#include <vector>
#include "Chest.h"

class UI
{
private:
    Player* player;
    Map* map;
    BattleUI BUI;
    Enemy* enemy;
    Event event;

    std::vector<Chest> chests; // honghonghogn

    Chest* getNearbyChest(Player& player); // honghonghogn

    bool mikuDefeated; // Jervis

public:
    UI();

    void clearScreen();

    void showMap(Map& map, Player& player);
    void showInventory(Player& player);
    void showCombat(Player& player, Enemy& enemy);
    // void showOccurrence();
    void showMerchant(Player& player);
    void showChest(Player& player, Chest& chest);

    bool run(Map& map, Player& player, bool& playerWon);


    void encounterEnemy(Player& player, Enemy* enemy);
};