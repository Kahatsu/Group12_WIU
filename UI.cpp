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

    Merchant merchant;

    bool merchantOpen = true;

    while (merchantOpen)
    {
        clearScreen();

        std::cout << "========================================" << std::endl;
        std::cout << "                MERCHANT                " << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << std::endl;
        std::cout << "        Welcome, Adventurer!" << std::endl;
        std::cout << std::endl;

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "1. Potion          FREE" << std::endl;
        std::cout << "2. SmokeBomb       FREE" << std::endl;
        std::cout << "3. Leave" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        char choice = _getch();

        // Potion
        if (choice == '1')
        {
            std::string item = merchant.getItem(1);

            player.addConsumable(item, 1);

            clearScreen();

            std::cout << "You received a " << item << "!" << std::endl;
            std::cout << std::endl;
            std::cout << "Press any key to continue...";

            _getch();
        }

        // SmokeBomb
        else if (choice == '2')
        {
            std::string item = merchant.getItem(2);

            player.addConsumable(item, 1);

            clearScreen();

            std::cout << "You received a " << item << "!" << std::endl;
            std::cout << std::endl;
            std::cout << "Press any key to continue...";

            _getch();
        }

        // Leave merchant
        else if (choice == '3')
        {
            merchantOpen = false;
        }
    }
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

        else if (input == 'q' || input == 'Q')
        {
            gameRunning = false;
        }
    }
}