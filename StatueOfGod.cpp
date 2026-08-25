#include "StatueOfGod.h"
#include "RandomNumGenerator.h"
#include<iostream>


StatueOfGod::StatueOfGod() :Enemy(20, 200, 200, "Statue Of God", 50) {
   
    allowedAttack = 1;
    
    
}

void StatueOfGod::attack(Player& player)
{
    RandomNumGenerator rannum;

    if (rannum.getRandomNum(1, 100) <= 15)
    {
        std::cout << "The Statue of God stuns you!\n";
        player.setStun(true);
        return;
    }

    if (rannum.getRandomNum(1, 100) <= 40)
    {
        special_attack(player);
    }
    else
    {
        std::cout << "Statue Of God strikes you\n";
        player.takeDamage(getDamage());
    }
}

void StatueOfGod::special_attack(Player& player) {
    std::cout << "The statue of God deems you unworthy of damaging it\n";
    std::cout << "The statue of God halves your current health\n";
    player.takeDamage(player.getHealth() / 2);
}

void StatueOfGod::setAttackRestriction()
{
    RandomNumGenerator rannum;

    allowedAttack = rannum.getRandomNum(1, 2);

    if (allowedAttack == 1)
    {
        std::cout << "The Statue of God allows BASIC ATTACK only!\n";
    }
    else
    {
        std::cout << "The Statue of God allows SPECIAL ATTACK only!\n";
    }
}




int StatueOfGod::getAllowedAttack()
{
    return allowedAttack;
}