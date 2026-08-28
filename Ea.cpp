#include "EA.h"
#include <iostream>
#include "textUtils.h"
#include <windows.h>

Ea::Ea()
    : Weapons(5, "Ea", 30, 100)
{
    specialVoiceLine = "Weapon\\EnumaElish.wav";
    equipVoiceLine = "Weapon\\Ea.wav";
    equipDialogue = "Wake up, Ea";

}

double Ea::specialWeaponAttack(double baseDamage)
{
   std::cout << "( Gaze upon the primordial truth )" << std::endl;
   slowPrint("Gensho no kotowari wo shiru ga ii" , 70);
   Sleep(600);
   slowPrint("Enuma... Elish!", 100);
   Sleep(600);
   return baseDamage * 8;
}

std::string Ea::getSpecialName()
{
    return "Enuma Elish (100 Mana)";
}

double Ea::reduceDamage(double damage)
{
    return damage * 0.5;
}