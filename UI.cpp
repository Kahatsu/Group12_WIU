#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include "Merchant.h"
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


void UI::showMerchant(Player& player)
{
    clearScreen();

    Merchant merchant(&player);
}


void UI::run(Map& map, Player& player)
{
    // Load starting area
    map.loadMap(0);

    // Place player on the map
    map.updateMap('P', player.getXcoord(), player.getYcoord());

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
            input == 'D')
        {
            player.move(input, &map);

            if (player.getSteppedOnMerchant())
            {
                showMerchant(player);
            }

            showMap(map, player);
        }

        else if (input == 'e' || input == 'E')
        {
            showInventory(player);
            showMap(map, player);
        }

        else if (input == 'f' || input == 'F')
        {
            // interact thingy put here
        }

        else if (input == 'q' || input == 'Q')
        {
            gameRunning = false;
        }
    }
}