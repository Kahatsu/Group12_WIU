#include <iostream>

//#include "RandomNumGenerator.h"

#include "Inventory.h"
#include "Map.h"
#include "Player.h"
#include <conio.h>
#include "RandomNumGenerator.h"
#include "UI.h"
#include "Game.h"
#include "BossMusic.h"


int main() {
	Game game;

	game.preGame();

	playBossMusic("BG\\Roaming_BG.wav");

	while (true) {
		game.runGame();
	}

}