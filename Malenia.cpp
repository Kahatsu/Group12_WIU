#include "Malenia.h"
#include <iostream>

Malenia::Malenia()
    : Enemy(40, 150, 150, "Malenia", 20)
{
    lifestealPercent = 0.05;
}

void Malenia::attack()
{
    std::cout << "Malenia attacks!" << std::endl;
}

void Malenia::special_attack()
{
    std::cout << "Malenia uses her special attack!, Waterfowl Dance" << std::endl;
}

double Malenia::getLifesteal()
{
    return lifestealPercent;
}