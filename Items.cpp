#include "Items.h"

Items::Items(double item_weight, std::string n){
    weight = item_weight;
    name = n;
}

double Items::getWeight(){
    return weight;
}

std::string Items::getName()
{
    return name;
}

