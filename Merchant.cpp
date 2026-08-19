#include "Merchant.h"

Merchant::Merchant()
{
}

std::string Merchant::getItem(int choice)
{
    switch (choice)
    {
    case 1:
        return "Potion";

    case 2:
        return "SmokeBomb";

    default:
        return "";
    }
}