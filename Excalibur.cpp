#include "Excalibur.h"
#include "Player.h"
#include <iostream>
#include "textUtils.h"
#include <windows.h>


Excalibur::Excalibur()
    : Weapons(10, "Excalibur +20", 20, 70)
{
    specialVoiceLine = "Weapon\\Excalibur.wav";
    equipVoiceLine = "Weapon\\ExcaliburEquip.wav";
    equipDialogue = "Your command, Master";
}

double Excalibur::specialWeaponAttack(double baseDamage)
{
    std::cout << "( Behold )" << std::endl;
    slowPrint("Miru ga ii", 70);
    Sleep(1400);
    slowPrint("Ex...", 90);
    Sleep(1200);
    slowPrint("Calibur!!", 120);
    Sleep(1500);
    return baseDamage * 4.5;
}

void Excalibur::onTurnStart(Player* player)
{
    double healAmount = player->getMaxHealth() * 0.1;
    std::cout << "The Avalon restores you (Healed 10%) " << std::endl;
    player->changeHealth(healAmount);
}

std::string Excalibur::getSpecialName()
{
    return "Excalibur (70 Mana)";
}