#include "Malenia.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Malenia::Malenia()
    : Enemy(40, 150, 150, "Malenia", 50)
{
    lifestealPercent = 0.05;
}

void Malenia::attack(Player* player)
{
    player->takeDamage(getDamage());

    double healAmount = getMaxHealth() * lifestealPercent;
    changeHealth(healAmount);

    if (getHealth() > getMaxHealth())
    {
        changeHealth(getMaxHealth() - getHealth());
    }

    std::cout << "Malenia attacks!" << std::endl;
    std::cout << "Malenia regained "
        << healAmount
        << " HP!" << std::endl;
}

void Malenia::special_attack(Player* player)
{
    // Random number of hits between 1 and 5
    int hits = rand() % 5 + 1;

    std::cout << "Malenia uses Waterfowl Dance!" << std::endl;
    std::cout << "It hits " << hits << " times!" << std::endl;

    for (int i = 0; i < hits; i++)
    {
        player->takeDamage(60);

        std::cout << "Hit " << i + 1 << "!" << std::endl;
    }
}

double Malenia::getLifesteal()
{
    return lifestealPercent;
}

void Malenia::setLifesteal(double percent)
{
    lifestealPercent = percent;
}
