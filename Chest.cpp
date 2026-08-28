#include "Chest.h"
#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include <conio.h>
#include <iostream>
#include "Chest.h"
#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

Chest::Chest() {
    money = 0;
    weapon = "";
    item = "";
    opened = false;

    x = 0;
    y = 0;
}

int Chest::getamtofmoney() {
    return money;
}

std::string Chest::getWeapon() {
    return weapon;
}


std::string Chest::getItem() {
    return item;
}

Chest::Chest(int m, std::string w, std::string i, int xPos, int yPos) {
    money = m;
    weapon = w;
    item = i;
    opened = false;

    x = xPos;
    y = yPos;
}

int Chest::getX()
{
    return x;
}

int Chest::getY()
{
    return y;
}

void Chest::openby(Player* player)
{
    if (opened) {
        return;
    }


    std::cout << "====================================" << std::endl;
    std::cout << "                CHEST               " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << std::endl;
    std::cout << "        You found a chest!" << std::endl;
    std::cout << std::endl;
    std::cout << "  Press any key to continue...";


    _getche();
    system("cls");



    if (money != 0) {

        player->gainMoney(money);
        std::cout << std::endl;
        std::cout << "You received " << money << " gold!" << std::endl;
        std::cout << std::endl;


    }

    // added by honghonghong
    std::string randomWeapon = getRandomWeapon();

    if (randomWeapon != "")
    {
        player->addWeapon(randomWeapon);

        std::cout << std::endl;
        std::cout << "You received a " << randomWeapon << "!" << std::endl;
        std::cout << std::endl;
    }
    // until here hehe

    if (item != "") {
        player->addConsumable(item);
        std::cout << std::endl;
        std::cout << "You received a " << item << "!" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Press X to quit" << std::endl;


    char c;

    do {
        c = _getche();
    } while (c != 'X' && c != 'x');

    opened = true;

}

// below added by honghong for weapon rolling in chest
std::vector<std::string> Chest::availableWeapons = {
    "Gauntlets",
    "Sword",
    "Bow",
    "Scythe",
    "Dagger",
    "LuminositeEternelle",
    "KanshouBakuya",
    "Excalibur",
    "ExcaliburMorgan",
    "Bab-ilu",
    "Ea",
    "ShadowMonarch" };

std::string Chest::getRandomWeapon()
{
    if (availableWeapons.empty())
    {
        return "";
    }

    int randomIndex = rand() % availableWeapons.size();

    std::string selectedWeapon = availableWeapons[randomIndex];

    // Remove the weapon so it cannot be selected again
    availableWeapons.erase(availableWeapons.begin() + randomIndex);

    return selectedWeapon;
}


void Chest::resetAvailableWeapons()
{
    availableWeapons = {
        "Gauntlets",
        "Sword",
        "Slingshot",
        "Bow",
        "Scythe",
        "Dagger",
        "LuminositeEternelle",
        "KanshouBakuya",
        "Excalibur",
        "Bab-ilu",
        "Ea",
        "ShadowMonarch"
    };
}