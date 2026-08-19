#pragma once
#include "Entity.h"
#include<string>

//READ ME!! enemies should all inherit this class. In the enemy class constructor remeber to pass on the health, max_health, name of the enemy type, amount of money to be dropped. e.g. Bomba::Bomba():Enemy(30,80,80,"Bomba",20)
//Any other function or variable that only your enemy type will need e.g. keeping track of number of turns before explosion for Bomba add in that class itself
//For Name please make first letter CAPITAL as its the name that we will use for the rest of the code.
//On initialisation health and max_health is the same so pass the same value for both

class Enemy :
    public Entity
{
private:
    int moneyToDrop;
public:
    Enemy(double damage, double health, double max_health, std::string name, int mtd);

    int getMoneyToDrop();
    
    //use this to attack ----- (for now just add the text that should be shown. The dealing of damage itself will probably be done with the takeDamage function.)
    virtual void attack(Entity& player) = 0;

    //use this to implement any special attacks e.g Bomba explosion  (Same as attack just add text for now unless attack has special feature that needs to be coded)
    virtual void special_attack(Entity& player) = 0;
};
