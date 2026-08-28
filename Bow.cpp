#include "Bow.h"#include "Bow.h"
#include <iostream>
#include "textUtils.h"

Bow::Bow()
    : Weapons(4, "Bow", 15, 30)
{}

double Bow::specialWeaponAttack(double baseDamage)
{
    slowPrint("Arrow Rain!", 30);
    return baseDamage * 2.0;
}

std::string Bow::getSpecialName()
{
    return "Arrow Rain";
}