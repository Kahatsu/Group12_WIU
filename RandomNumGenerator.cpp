#include <random>

#include "RandomNumGenerator.h"

int RandomNumGenerator::getRandomNum(int min, int max){
	static std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<int> distrib(min, max);
	return distrib(gen);
}
