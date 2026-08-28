#pragma once
#include "Items.h"
#include <string>
class Armor :
    public Items
{
private:
    float mitigationAmt;
public:
    Armor(double weight, std::string name, float mitigate);
    
    float getMitigationAmt();
};

