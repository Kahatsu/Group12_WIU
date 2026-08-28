#include "Malenia.h"
#include <iostream>
#include "RandomNumGenerator.h"

Malenia::Malenia()
    : Enemy(30, 300, 300, "Malenia", 100)
{
    lifestealPercent = 0.05;
}

void Malenia::attack(Player* player)
{
    RandomNumGenerator rannum;

    // 15% chance to use special attack
    if (rannum.getRandomNum(1, 100) <= 15)
    {
        special_attack(player);
    }
    else
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
}

void Malenia::special_attack(Player* player)
{
    // Random number of hits between 1 and 5
    RandomNumGenerator rannum;
    int hits = rannum.getRandomNum(1, 5);

    std::cout << "Malenia uses Waterfowl Dance!" << std::endl;
    std::cout << "It hits " << hits << " times!" << std::endl;

    for (int i = 0; i < hits; i++)
    {
        player->takeDamage(20);

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
