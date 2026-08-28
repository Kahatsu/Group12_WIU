#include "Armor.h"

Armor::Armor(double weight, std::string name, float mitigate) : Items(weight, name) {
	mitigationAmt = mitigate;
}
float Armor::getMitigationAmt()
{
	return mitigationAmt;
}
;