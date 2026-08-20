#include <iostream>
#include <conio.h>
#include "UI.h"
#include "Merchant.h"
#include "Player.h"
#include "Entity.h"

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

Merchant::Merchant(Player* player) : Entity(50, 100000, 100000, "Miku")
{
    char continueKey{};
    bool merchantOpen = true;

    const int potionPrice = 5;
    const int smokeBombPrice = 3;

    while (merchantOpen)
    {
        std::cout << "\033[H\033[2J" << std::flush;

        std::cout << "========================================" << std::endl;
        std::cout << "                MERCHANT                " << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << std::endl;
        std::cout << "  Welcome, Adventurer!, my name is Miku" << std::endl;
        std::cout << std::endl;

        std::cout << "Gold: " << player->getMoney() << std::endl;

        std::cout << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "1. Potion          " << potionPrice << " Gold" << std::endl;
        std::cout << "2. SmokeBomb       " << smokeBombPrice << " Gold" << std::endl;
        std::cout << "3. Leave" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        char choice = _getch();

        // Potion
        if (choice == '1')
        {
            if (player->getMoney() >= potionPrice)
            {
                std::string item = getItem(1);

                player->loseMoney(potionPrice);
                player->addConsumable(item);

                std::cout << "\033[H\033[2J" << std::flush;

                std::cout << "You bought a " << item << "!" << std::endl;
                std::cout << "You spent " << potionPrice << " Gold." << std::endl;
                std::cout << "Remaining Gold: " << player->getMoney() << std::endl;
            }
            else
            {
                std::cout << "\033[H\033[2J" << std::flush;

                std::cout << "You don't have enough Gold!" << std::endl;
            }

            std::cout << std::endl;
            std::cout << "Press any key to continue...";
            continueKey = _getch();
        }

        // SmokeBomb
        else if (choice == '2')
        {
            if (player->getMoney() >= smokeBombPrice)
            {
                std::string item = getItem(2);

                player->loseMoney(smokeBombPrice);
                player->addConsumable(item);

                std::cout << "\033[H\033[2J" << std::flush;

                std::cout << "You bought a " << item << "!" << std::endl;
                std::cout << "You spent " << smokeBombPrice << " Gold." << std::endl;
                std::cout << "Remaining Gold: " << player->getMoney() << std::endl;
            }
            else
            {
                std::cout << "\033[H\033[2J" << std::flush;

                std::cout << "You don't have enough Gold!" << std::endl;
            }

            std::cout << std::endl;
            std::cout << "Press any key to continue...";
            continueKey = _getch();
        }

        // Leave merchant
        else if (choice == '3')
        {
            merchantOpen = false;
        }
    }
}
