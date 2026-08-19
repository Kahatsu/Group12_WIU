#include<string>
#pragma once
class Entity{
private:
	double damage;
	//health is the entitys current health, max_health is the maximum health the entity can have
	double health;
	double max_health;
	int cooldown;
	std::string name;
public:
	Entity(double d, double h, double mh, std::string n);
	
	//call this function to let enemy take damage
	void takeDamage(double damageTaken);

	double getDamage();
	//used to apply buffs/debuffs
	void changeDamage(double change);
	
	double getHealth();
	void changeHealth(double change);

	double getMaxHealth();
	void changeMaxHealth(double change);

	int getCooldown();
	void setCooldown(int new_cooldown);
};



