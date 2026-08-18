#include "Entity.h"

Entity::Entity(double d, double h, double mh){
	damage = d;
	health = h;
	max_health = mh;
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


