#include "Sword.h"
#include <iostream>
#include "textUtils.h"
#include <windows.h>

Sword::Sword()
    : Weapons(5, "Sword", 15, 80)
{
    specialVoiceLine = "Weapon\\Sword.wav";
    equipVoiceLine = "Weapon\\SwordEquip.wav";
    equipDialogue = "I am the storm that is approaching..";

}

double Sword::specialWeaponAttack(double baseDamage)
{
    slowPrint("You shall die!", 70);
    Sleep(1200);
    return baseDamage * 4.0;
}

std::string Sword::getSpecialName()
{
    return "Judgement Cut (80 Mana)";
}
