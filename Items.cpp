#include "Items.h"

Items::Items(double item_weight){
    weight = (item_weight);
}

const double Items::getWeight(){
    return weight;
}
