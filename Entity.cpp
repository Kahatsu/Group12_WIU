#include "Entity.h"
#include <string>

Entity::Entity(double d, double h, double mh, std::string n){
	damage = d;
	health = h;
	max_health = mh;
	name = n;
	cooldown = 0;
}

void Entity::takeDamage(double damageTaken)
{
	health = health - damageTaken;
}

double Entity::getDamage()
{
	return damage;
}

void Entity::changeDamage(double change)
{
	damage + change;
}

 double Entity::getHealth()
{
	return health;
}

 void Entity::changeHealth(double change)
 {
	 health + change;
 }

 double Entity::getMaxHealth()
 {
	 return max_health;
 }

 void Entity::changeMaxHealth(double change)
 {
	 max_health + change;
 }

 int Entity::getCooldown()
 {
	 return cooldown;
 }

 void Entity::setCooldown(int new_cooldown)
 {
	 cooldown = new_cooldown;
 }


