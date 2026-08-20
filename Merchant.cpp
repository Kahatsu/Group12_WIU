#include <iostream>
#include <conio.h>
#include "UI.h"
#include "Merchant.h"
#include "Player.h"

std::string Merchant::getItem(int choice)
{
    switch (choice)
    {
    case 1:
        return "Potion";

    case 2:
        return "SmokeBomb";

    default:
        return "";
    }
}

Merchant::Merchant(Player* player)
{
    bool merchantOpen = true;

    while (merchantOpen)
    {
        std::cout << "\033[H\033[2J" << std::flush;

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
            std::string item = getItem(1);

            player -> addConsumable(item, 1);

            std::cout << "\033[H\033[2J" << std::flush;

            std::cout << "You received a " << item << "!" << std::endl;
            std::cout << std::endl;
            std::cout << "Press any key to continue...";

            _getch();
        }

        // SmokeBomb
        else if (choice == '2')
        {
            std::string item = getItem(2);

            player -> addConsumable(item, 1);

            std::cout << "\033[H\033[2J" << std::flush;

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
