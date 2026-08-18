#include "Entity.h"
#include <string>

Entity::Entity(double d, double h, double mh, std::string n){
	damage = d;
	health = h;
	max_health = mh;
	name = n;
}

void Entity::takeDamage(double damageTaken)
{
	health = health - damageTaken;
}

double Entity::getDamage()
{
	return damage;
}

double Entity::changeDamage(double change)
{
	return damage + change;
}

 double Entity::getHealth()
{
	return health;
}

 double Entity::changeHealth(double change)
 {
	 return health + change;
 }

 double Entity::getMaxHealth()
 {
	 return max_health;
 }

 double Entity::changeMaxHealth(double change)
 {
	 return max_health + change;
 }




