#include "Potion.h"

Potion::Potion(int heal) {
	healAmt = heal;
}

double Potion::getHealAmt() {
	return healAmt;
}