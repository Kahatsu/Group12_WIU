#pragma once
#include "Potion.h"
#include "Weapons.h"
#include <vector>
#include <string>

class Player;

class Chest
{
private:
    int x;
    int y;
    int money;
    std::string item;
    std::string weapon;
    bool opened;

    // Weapons that have not been given out yet
    static std::vector<std::string> availableWeapons;

public:

    int getamtofmoney();
    std::string getWeapon();
    std::string getItem();

    int getX();
    int getY();

    Chest();
    Chest(int m, std::string w, std::string i, int xPos, int yPos); // honghong added coordinates.

    void openby(Player* player);

    // Gets a random weapon without duplicates
    std::string getRandomWeapon();

    // Resets the weapon pool
    static void resetAvailableWeapons();
};