#include "LuminositeEternelle.h"
#include "Player.h"
#include <iostream>
#include "textUtils.h"


LuminositeEternelle::LuminositeEternelle()
    : Weapons(5, "LuminositeEternelle", 15, 80)
{
    buffActive = false;
    equipDialogue = "Oh flag of mine, protect our comrades";
}

bool LuminositeEternelle::buffSpecial(Player* player)
{
    if (buffActive)
    {
        slowPrint("Luminosite Eternelle has already been activated!", 30);
        return false;
    }

    slowPrint("Luminosite Eternelle!", 60);

    double damageIncrease = player->getDamage() * 0.50;
    double hpIncrease = player->getMaxHealth() * 0.50;
    double ManaIncrease = player->getMaxMana() * 0.20;

    player->changeDamage(damageIncrease);
    player->changeMaxHealth(hpIncrease);
    player->changeHealth(hpIncrease);
    player->changeMana(ManaIncrease);
    buffActive = true;
    std::cout << "Attack increased by 50%!" << std::endl;
    std::cout << "HP increased by 50%!" << std::endl;
    std::cout << "Mana increased by 20%!" << std::endl;
    return true;
}

std::string LuminositeEternelle::getSpecialName()
{
    return "Luminosite Eternelle (80 Mana)";
}