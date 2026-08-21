#pragma once
#include "Player.h"
class Event
{
public:
	char option;
	int choice;


//Event distributor
	void triggerevent(Player& Player);

//Function to call each specific event 

	void event_Fountain(Player& Player);//1
	void event_Shrine(Player& Player);//2
	void event_WheelOfFate(Player& Player);//3
	void event_AnimalLover(Player& Player);//4
	void event_TarotMania(Player& Player);//5
	void event_Goddess(Player& Player);//6
	void event_DevilsDeal(Player& Player);//7
	void event_Smithy(Player& Player);//8
	void event_DatingSim(Player& Player);//9
	void event_FourthWall(Player& Player);//10





};

