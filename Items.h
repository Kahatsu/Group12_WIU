#include<string>

#pragma once
class Items {
private:
	double weight;
	std::string name;
public:
	Items(double item_weight, std::string name);

	double getWeight();
	std::string getName();
};
