#include "Entity.h"
#include <string>

Entity::Entity(double d, double h, double mh, int m, int mm, std::string n)
{
	damage = d;
	health = h;
	max_health = mh;

	mana = m;
	max_mana = mm;

	name = n;
	cooldown = 0;
	DOTcounter = 0;

	stun = false;
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
	damage = damage + change;
}

double Entity::getHealth()
{
	return health;
}

void Entity::changeHealth(double change)
{
	health = health + change;

	if (health < 0)
	{
		health = 0;
	}

	if (health > max_health)
	{
		health = max_health;
	}
}

double Entity::getMaxHealth()
{
	return max_health;
}

void Entity::changeMaxHealth(double change)
{
	max_health = max_health + change;
}

int Entity::getCooldown()
{
	return cooldown;
}

void Entity::setCooldown(int new_cooldown)
{
	cooldown = new_cooldown;
}

// Mana
int Entity::getMana()
{
	return mana;
}

void Entity::changeMana(int change)
{
	mana += change;

	if (mana < 0)
	{
		mana = 0;
	}

	if (mana > max_mana)
	{
		mana = max_mana;
	}
}

int Entity::getMaxMana()
{
	return max_mana;
}

void Entity::changeMaxMana(int change)
{
	max_mana += change;
}

// Damage over time (DOT)
void Entity::changeDOTCounter(int value)
{
	DOTcounter = value;
}

int Entity::getDOTCounter()
{
	return DOTcounter;
}

void Entity::takeDot(int damage)
{
	if (DOTcounter > 0)
	{
		takeDamage(damage);
		DOTcounter--;
	}
}

std::string Entity::getName()
{
	return name;
}

bool Entity::getStun()
{
	return stun;
}

void Entity::setStun(bool state)
{
	stun = state;
}
