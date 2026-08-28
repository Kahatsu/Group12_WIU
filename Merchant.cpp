#include "Merchant.h"
#include "Player.h"
#include <iostream>
#include <conio.h>
#include "Armor.h"

Merchant::Merchant()
    : Entity(50, 100000, 100000, 0, 0, "Miku")
{
}

std::string Merchant::getItem(int choice)
{
    switch (choice)
    {
    case 1:
        return "Health Potion";
        break;

    case 2:
        return "SmokeBomb";
        break;

    case 3:
        return "Mana Potion";
        break;

    case 4:
        return "Iron Armor";
        break;

    case 5:
        return "Diamond Armor";
        break;

    case 6:
        return "Netherite Armor";
        break;

    default:
        return "";
    }
}

int Merchant::getPrice(int choice)
{
    switch (choice)
    {
    case 1:
        return 5;      // Health Potion
        break;

    case 2:
        return 3;      // SmokeBomb
        break;

    case 3:
        return 5;      // Mana Potion
        break;

    case 4:
        return 10;      // Iron Armor
        break;

    case 5:
        return 100;    // Diamond Armor
        break;

    case 6:
        return 200;    // Netherite Armor
        break;

    default:
        return 0;
    }
}

void Merchant::openShop(Player* player)
{
    bool merchantOpen = true;

    while (merchantOpen)
    {
        system("cls");

        std::cout << "==================================================" << std::endl;
        std::cout << "                    MIKU'S SHOP                   " << std::endl;
        std::cout << "==================================================" << std::endl;

        std::cout << R"(
        </\>_</\>   
       / ( o.o ) \  
      /   > ^ <   \
     /  /|  |  |\  \
     | / |  *  | \ |
     |   |     |   | 
     \             /
    )" << std::endl;

        std::cout << "        Welcome, Adventurer! My name is Miku." << std::endl;
        std::cout << std::endl;

        std::cout << "        Gold: " << player->getMoney() << " G" << std::endl;

        std::cout << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        std::cout << "[1] Health Potion      5 G" << std::endl;
        std::cout << "[2] SmokeBomb          3 G" << std::endl;
        std::cout << "[3] Mana Potion        5 G" << std::endl;
        if (player->hasArmor("Iron Armor"))
        {
            std::cout << "[4] Iron Armor        OWNED" << std::endl;
        }
        else
        {
            std::cout << "[4] Iron Armor        10 G" << std::endl;
        }

        if (player->hasArmor("Diamond Armor"))
        {
            std::cout << "[5] Diamond Armor     OWNED" << std::endl;
        }
        else
        {
            std::cout << "[5] Diamond Armor    100 G" << std::endl;
        }

        if (player->hasArmor("Netherite Armor"))
        {
            std::cout << "[6] Netherite Armor   OWNED" << std::endl;
        }
        else
        {
            std::cout << "[6] Netherite Armor  200 G" << std::endl;
        }

        std::cout << "[7] Leave" << std::endl;

        std::cout << "--------------------------------------------------" << std::endl;

        char choice = _getch();

        if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6')
        {
            int itemChoice = choice - '0';

            std::string item = getItem(itemChoice);
            int price = getPrice(itemChoice);

            system("cls");

            if (item == "Iron Armor" ||
                item == "Diamond Armor" ||
                item == "Netherite Armor")
            {
                // Check if player already owns the armor
                if (player->hasArmor(item))
                {
                    std::cout << "You already own " << item << "!" << std::endl;
                }
                else if (player->getMoney() >= price)
                {
                    player->loseMoney(price);
                    player->addArmor(item);

                    std::cout << "You bought a " << item << "!" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Cost: " << price << " G" << std::endl;
                    std::cout << "Remaining Gold: "
                        << player->getMoney() << " G" << std::endl;
                }
                else
                {
                    std::cout << "You don't have enough Gold!" << std::endl;
                }
            }
            else
            {
                if (player->getMoney() >= price)
                {
                    player->loseMoney(price);
                    player->addConsumable(item);

                    std::cout << "You bought a " << item << "!" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Cost: " << price << " G" << std::endl;
                    std::cout << "Remaining Gold: "
                        << player->getMoney() << " G" << std::endl;
                }
                else
                {
                    std::cout << "You don't have enough Gold!" << std::endl;
                }
            }

            std::cout << std::endl;
            std::cout << "Press any key to continue...";
            _getch();
        }
        else if (choice == '7')
        {
            merchantOpen = false;
        }
    }
}