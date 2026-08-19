#include "UI.h"
#include "Inventory.h"
#include <conio.h>
#include <iostream>

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

    // Draw the map using your friend's Map class
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
    std::cout << "[WASD] Move       [E] Inventory       [Q] Quit" << std::endl;
}


void UI::showInventory()
{
    clearScreen();

    std::cout << "========================================" << std::endl;
    std::cout << "                INVENTORY               " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << std::endl;

    std::cout << "1. Items" << std::endl;
    std::cout << "2. Weapons" << std::endl;
    std::cout << "3. Armors" << std::endl;

    std::cout << std::endl;
    std::cout << "[Press E to return]" << std::endl;
}


//void UI::showCombat()
//{
//    clearScreen();
//
//    std::cout << "========================================" << std::endl;
//    std::cout << "                 COMBAT                 " << std::endl;
//    std::cout << "========================================" << std::endl;
//}


//void UI::showOccurrence()
//{
//    clearScreen();
//
//    std::cout << "========================================" << std::endl;
//    std::cout << "               OCCURRENCE               " << std::endl;
//    std::cout << "========================================" << std::endl;
//}


//void UI::showMerchant()
//{
//    clearScreen();
//
//    std::cout << "========================================" << std::endl;
//    std::cout << "                MERCHANT                " << std::endl;
//    std::cout << "========================================" << std::endl;
//}


void UI::run(Map& map, Player& player)
{
    bool inventoryOpen = false;

    // Load starting area
    map.loadMap(0);

    // Place player on the map
    map.updateMap('P', player.getXcoord(), player.getYcoord());

    showMap(map, player);

    bool gameRunning = true;

    while (gameRunning)
    {
        char input = _getch();

        if (!inventoryOpen)
        {
            if (input == 'w' ||
                input == 'W' ||
                input == 'a' ||
                input == 'A' ||
                input == 's' ||
                input == 'S' ||
                input == 'd' ||
                input == 'D')
            {
                player.move(input, &map);
                showMap(map, player);
            }

            else if (input == 'e' || input == 'E')
            {
                inventoryOpen = true;
                showInventory();
            }

            else if (input == 'q' || input == 'Q')
            {
                gameRunning = false;
            }
        }
        else
        {
            if (input == 'e' || input == 'E')
            {
                inventoryOpen = false;
                showMap(map, player);
            }
        }
    }
}