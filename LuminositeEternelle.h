#pragma once
#include "Weapons.h"

class LuminositeEternelle : public Weapons
{
private:
    bool buffActive;

public:
    LuminositeEternelle();

    bool buffSpecial(Player* player) override;
    std::string getSpecialName() override;
};