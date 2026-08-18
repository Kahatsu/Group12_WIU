#include<string>
#pragma once
class Entity{
private:
	double damage;
	//health is the entitys current health, max_health is the maximum health the entity can have
	double health;
	double max_health;
	std::string name;
public:
	Entity(double d, double h, double mh, std::string n);
	
	//call this function to let enemy take damage
	void takeDamage(double damageTaken);

	double getDamage();
	//used to apply buffs/debuffs
	double changeDamage(double change);
	
	double getHealth();
	double changeHealth(double change);

	double getMaxHealth();
	double changeMaxHealth(double change);
};

