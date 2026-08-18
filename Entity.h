#pragma once
class Entity{
private:
	double damage;
	double health;
	double max_health;
public:
	Entity(double d, double h, double mh);
	
	double getDamage();
	double changeDamage(double change);
	
	double getHealth();
	double changeHealth(double change);

	double getMaxHealth();
	double changeMaxHealth(double change);
};

