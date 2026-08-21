#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Chest.h"
#include <conio.h>
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
#include "battleUI.h"
#include "NiuLai.h"

UI::UI()
{
    player = new Player;
    map = new Map;
    enemy = new NiuLai;
}

void UI::clearScreen()
{
    system("cls");
}

void UI::showMap(Map& map, Player& player)
{
    clearScreen();

    std::cout << "========================================" << std::endl;
    std::cout << "                 DUNGEON                " << std::endl;
    std::cout << "========================================" << std::endl;

    // Draw the map using friend's Map class
    map.drawMap();

    std::cout << "----------------------------------------" << std::endl;

    std::cout << "HP: "
        << player.getHealth()
        << "/"
        << player.getMaxHealth()
        << "     ATK: "
        << player.getDamage()
        << "     GOLD: "
        << player.getMoney()
        << std::endl;

    std::cout << "Weapon: Bare Fist" << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "[WASD] Move  [E] Inventory  [F] Interact  [Q] Quit" << std::endl;
}


void UI::showInventory(Player& player)
{
    clearScreen();

    std::cout << "========================================" << std::endl;
    std::cout << "                INVENTORY               " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    player.openInventory();
}

void UI::showCombat(Player& player, Enemy& enemy)
{
    clearScreen();
    BUI.showBattle(player, enemy);

    std::cout << "\nPress any key to continue...";
    _getch();
}


//void UI::showOccurrence()
//{
//    clearScreen();
//
//    std::cout << "========================================" << std::endl;
//    std::cout << "               OCCURRENCE               " << std::endl;
//    std::cout << "========================================" << std::endl;
//}


void UI::showMerchant(Player& player)
{
    clearScreen();

    Merchant merchant(&player);
}


void UI::showChest(Player& player, Chest& chest)
{
    clearScreen();

    chest.open(&player);
}


void UI::run(Map& map, Player& player)
{
    // Load starting area
    map.loadMap(0);
    Chest chest(5, "weap", "bomb");
    // Place player on the map
    //map.updateMap('P', player.getXcoord(), player.getYcoord());

    showMap(map, player);


    bool gameRunning = true;

    while (gameRunning)
    {
        char input = _getch();

        if (input == 'w' ||
            input == 'W' ||
            input == 'a' ||
            input == 'A' ||
            input == 's' ||
            input == 'S' ||
            input == 'd' ||
            input == 'D' ||
            input == 'f')
        {
            player.move(input, &map);

            if (player.getInteract())
            {
                if (player.getInteractType() == 'M') {
                    showMerchant(player);

                }
                else if (player.getInteractType() == 'C') {
                    showChest(player, chest);
                }
                else if (player.getInteractType() == 'N') {
                    showCombat(player, *enemy);
                }


                player.setInteract();
            }

            showMap(map, player);
        }

        else if (input == 'e' || input == 'E')
        {
            showInventory(player);
            showMap(map, player);
        }

        else if (input == 'p' || input == 'P')
        {
            gameRunning = false;
        }
    }
}

void UI::encounterEnemy()
{
    int percent{};
    RandomNumGenerator ranNum;
    percent = ranNum.getRandomNum(1, 100);

    //10% chance
    if (percent <= 10) {
        BUI.showBattle(*player,*enemy);
    }
}
