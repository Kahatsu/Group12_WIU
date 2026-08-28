#include "Inventory.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <array>
#include <limits>

Inventory::Inventory()
{
    weapons.reserve(11);
    armors.reserve(3);

    consumables_list =
    {
        "Health Potion",
        "SmokeBomb",
        "Mana Potion",
        "GOLDEN TURD"
    };

    weapons_list =
    {
        "Gauntlets",
        "Sword",
        "Bow",
        "Scythe",
        "Dagger",
        "Excalibur",
        "Bab-ilu",
        "Luminosite Eternelle",
        "KanshouBakuya",
        "ShadowMonarch",
        "ExcaliburMorgan"
    };

    armors_list =
    {
        "Iron Armor",
        "Diamond Armor",
        "Netherite Armor"
    };

    useitem = false;
}


void Inventory::addItems(Items& item)
{
    // Check if consumable
    for (int i = 0; i < consumables_list.size(); i++)
    {
        if (item.getName() == consumables_list[i])
        {
            addConsumable(item.getName());
        }
    }

    // Check if weapon
    for (int i = 0; i < weapons_list.size(); i++)
    {
        if (item.getName() == weapons_list[i])
        {
            addWeapon(item.getName());
        }
    }

    // Check if armor
    for (int i = 0; i < armors_list.size(); i++)
    {
        if (item.getName() == armors_list[i])
        {
            addArmor(item.getName());
        }
    }
}


void Inventory::addConsumable(std::string item)
{
    consumables[item]++;
}


void Inventory::removeConsumable(std::string item)
{
    consumables[item]--;

    if (consumables[item] <= 0)
    {
        consumables.erase(item);
    }
}


void Inventory::addWeapon(std::string weapon)
{
    if (std::find(weapons.begin(), weapons.end(), weapon) == weapons.end())
    {
        weapons.push_back(weapon);
    }
}


void Inventory::dropWeapon(std::string weapon)
{
    auto it = std::find(weapons.begin(), weapons.end(), weapon);

    if (it != weapons.end())
    {
        weapons.erase(it);
    }
}


void Inventory::addArmor(std::string armor)
{
    if (std::find(armors.begin(), armors.end(), armor) == armors.end())
    {
        armors.push_back(armor);
    }
}


void Inventory::dropArmor(std::string armor)
{
    auto it = std::find(armors.begin(), armors.end(), armor);

    if (it != armors.end())
    {
        armors.erase(it);
    }
}


void Inventory::clearConsole()
{
    std::cout << "\033[H\033[2J" << std::flush;
}


std::string Inventory::displayInventoryUI()
{
    std::cout << "1. Items  2. Weapons  3. Armors:  ";

    char choice{};
    std::cin >> choice;

    clearConsole();

    switch (choice)
    {
    case '1':
    {
        std::cout << "Items: \n";

        int index = 0;

        for (auto& item : consumables)
        {
            std::cout << index + 1
                << " "
                << item.first
                << "  x"
                << item.second
                << "\n";

            index++;
        }

        std::cout << index + 1 << ". Escape\n";
        std::cout << "Option: ";

        int option{};
        std::cin >> option;

        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error state

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input!\n";
            return "";
        }

        if (option < 1 || option > index)
        {
            return "";
        }

        int counter{};

        for (auto& item : consumables)
        {
            if (counter == option - 1)
            {
                std::string selectedItem = item.first;

                std::cout << "You consumed "
                    << selectedItem
                    << "\n";

                useitem = true;

                removeConsumable(selectedItem);

                return selectedItem;
            }

            counter++;
        }

        return "";
    }

    case '2':
    {
        for (int i = 0; i < weapons.size(); i++)
        {
            std::cout << i + 1
                << ". "
                << weapons[i]
                << "\n";
        }

        std::cout << weapons.size() + 1 << ". Escape\n";
        std::cout << "Option: ";

        int option{};
        std::cin >> option;

        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error state

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input!\n";
            return "";
        }

        if (option < 1 || option > static_cast<int>(weapons.size()))
        {
            return "";
        }

        return weapons[option - 1];
    }

    case '3':
    {
        for (int i = 0; i < armors.size(); i++)
        {
            std::cout << i + 1
                << ". "
                << armors[i]
                << "\n";
        }

        std::cout << armors.size() + 1 << ". Escape\n";
        std::cout << "Option: ";

        int option{};
        std::cin >> option;

        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error state

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input!\n";
            return "";
        }

        if (option < 1 || option > static_cast<int>(armors.size()))
        {
            return "";
        }

        std::cout << "You have equipped "
            << armors[option - 1]
            << "\n";

        return armors[option - 1];


    }

    default:
        return "";
    }

    return "";
}


bool Inventory::getuseitem()
{
    return useitem;
}


void Inventory::setuseitem(bool u)
{
    useitem = u;
}

bool Inventory::hasArmor(std::string armor)
{
    return std::find(armors.begin(), armors.end(), armor) != armors.end();
}