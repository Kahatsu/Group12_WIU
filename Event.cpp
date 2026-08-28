#include "Event.h"
#include <iostream>
#include <ctime>
#include "RandomNumGenerator.h"
#include "Entity.h"
#include "Player.h"
#include "textUtils.h"
#include <conio.h>


void Event::occurencegenerator(Player& Player)
{

	RandomNumGenerator numgen;
	int eventNum = numgen.getRandomNum(1, 10);
	int choice;//1-4
	char option;//Y(es)/ N(o)

	switch (eventNum)
	{
	case 1:event_Fountain(Player);//can repeat
		break;

	case 2:event_Shrine(Player);//can repeat
		break;

	case 3:event_WheelOfFate(Player);//can repeat
		break;
	case 4:
		event_AnimalLover(Player);//can't repeat
		break;
	case 5:
		event_TarotMania(Player);//can't repeat
		break;
	case 6:
		event_Goddess(Player);//can't repeat
		break;
	case 7:
		event_DevilsDeal(Player);//can't repeat
		break;
	case 8:
		event_HealthForCash(Player);//can repeat
		break;
	case 9:
		event_DatingSim(Player);//can't repeat
		break;
	case 10:
		event_FourthWall(Player);//can't repeat
		break;
	default:
		break;

	}
}

void Event::event_Fountain(Player& Player)//can repeat
{
	int choice;//1-4

	slowPrint("You approach a fountain with glistening water reflecting yourself", 10);
	slowPrint("Do you:", 10);
	std::cout << "1.Drink the water" << std::endl;
	std::cout << "2.Wash your wounds with the water" << std::endl;
	std::cout << "3.Leave" << std::endl;
	std::cin >> choice;

	if (choice == 1)
	{
		slowPrint("You embrace wrath, anger builds within yourself", 10);
		Player.changeDamage(5);
		_getch();
		//player attack increase by 5
	}
	if (choice == 2)
	{
		slowPrint("You feel a sense of tranquility wrap around your being as your wounds start to close.", 10);
		Player.changeHealth(20);
		_getch();
		//player health restored by 20

	}
	if (choice == 3)
	{
		slowPrint("You walk away from the fountain", 10);
		_getch();

	}
	else {

	}
}


void Event::event_Shrine(Player& Player)//can repeat
{
	char option;//Y(es)/ N(o)

	slowPrint("A shrine stands in front of you and at the foot of its entrance a box with a hole just big enough for coins.", 10);
	slowPrint("Will you test your luck with fate? (50 coins) Yes / No", 10);
	std::cin >> option;
	if (option == 'Y' || option == 'y')
	{
		RandomNumGenerator numgen;
		int rngNum1 = numgen.getRandomNum(1, 3);
		Player.loseMoney(50);
		switch (rngNum1)
		{
		case 1:
			slowPrint("The lives which you have taken come back to haunt your very living soul", 10);
			//player -15hp
			Player.changeHealth(-15);
			_getch();

			break;
		case 2:
			slowPrint("Fate has deemed you worthy of that of a warriors reward.", 10);
			//player receives 200 moneh
			Player.gainMoney(200);
			_getch();

			break;
		case 3:
			slowPrint("Fate has decided that your journey has been arduous, it is time for a little break", 10);
			//(hp restored by 20)
			Player.changeHealth(20);
			_getch();

			break;
		default:
			break;
		}
	}
	if (option == 'N' || option == 'n')
	{
		slowPrint("You admire the shrine for a minute reflecting on your decisions before taking your leave", 10);
		_getch();

	}
	else {

	}
}


void Event::event_WheelOfFate(Player& Player)//Can repeat
{
	char option;//Y(es)/ N(o)
	slowPrint("A wheel stands before you. Go on adventurer spin it and let fate define your very means.", 10);
	slowPrint("Will you do it? Y/N", 10);
	std::cin >> option;
	if (option == 'Y' || option == 'y')
	{
		RandomNumGenerator numgen;
		int rngNum2 = numgen.getRandomNum(1, 100);
		if (rngNum2 >= 1 && rngNum2 <= 10)
		{
			slowPrint("You feel a sense of vitality overcome you.", 10);
			//heal 50hp of player 
			Player.changeHealth(50);
			_getch();

		}

		if (rngNum2 >= 31 && rngNum2 <= 70)
		{
			slowPrint("You feel significantly stronger like you could lift a bull.", 10);
			//attck increase 15 points
			Player.changeDamage(15);
			_getch();

		}

		if (rngNum2 >= 71 && rngNum2 <= 99)
		{
			slowPrint("Thorns entangle you wrapping you in pain and anguish.", 10);
			Player.changeHealth(-35);
			_getch();

			//hp -35hp
		}

		if (rngNum2 == 100)
		{
			slowPrint("THE WHEEL HAS CALLED FOR THE UTMOST PUNISHMENT FOOR YOUR CURIOUSITY", 10);
			Player.changeHealth(-35);
			_getch();

			//hp -90hp
		}

	}
	if (option == 'N' || option == 'n')
	{
		slowPrint("You leave the wheel alone satisfied with yourself for not giving into temptation...for now...", 10);
		_getch();

	}
	else {

	}
}


void Event::event_AnimalLover(Player& Player)//Cannot repeat more than once
{
	int choice;//1-4
	slowPrint("You see a pack of bloodhounds chained with a sign stating: BEWARE THE CHAINS THAT BIND THESE HELLISH PUPS! Do you:", 10);
	std::cout << "1.Free the hounds." << std::endl;
	std::cout << "2.Decide to move on." << std::endl;
	std::cin >> choice;
	if (choice == 1)
	{
		slowPrint("You free the hounds and watch them run into the horizon but the very chains that binded them have imposed a punishment on you", 10);
		Player.changeHealth(-25);
		_getch();

		//player health -25
		Player.setEventLock(true);
	}

	if (choice == 2)
	{
		slowPrint("You turn back to look at the dogs as you walked onwards, guilt eats you up from inside, but you have a mission to finish.", 10);
		_getch();

	}
	else {

	}

}


void Event::event_TarotMania(Player& Player)//Cannot repeat more than once
{
	int choice;//1-4
	slowPrint("As you walk further down, you approach a table with tarot cards faced up.\u201c Adventurer, pick a card as you please.", 10);
	std::cout << "1.The Fool" << std::endl;  //Player gains +5 attack but loses 10hp 
	std::cout << "2.The Emperor" << std::endl;//Player 
	std::cout << "3.The Devil" << std::endl;//- Player gains + 15 attack but at the cost of - 35hp
	std::cout << "4.The Star" << std::endl;// - Player is healed for 15hp
	std::cout << "5.The Moon" << std::endl;//- Player attack has increased by 5 but lost 10hp
	std::cin >> choice;
	if (choice == 1)
	{
		slowPrint("Ah the Fool, good choice. But, do not be blinded by the path in front of you.", 10);
		slowPrint("You feel stronger than before but you also sense a loss of vitality.", 10);
		slowPrint("Your attack has increased by 5 but you lost 10hp.", 10);
		Player.changeHealth(-10);
		Player.changeDamage(5);
		_getch();

		Player.setEventLock(true);
	}
	if (choice == 2)
	{
		slowPrint("The Emperor, I see... Well, every good leader needs a good start", 10);
		slowPrint("Your attack has been increased by 10.", 10);
		Player.changeDamage(10);
		_getch();

	}
	if (choice == 3)
	{
		slowPrint("The Devil, daring choice indeed. But, as the saying goes, you cannot deal with the devil without losing abit of your soul.", 10);
		slowPrint("Your strenghts increases greatly but you feel a loss of your soul", 10);
		slowPrint("Your attack has increased by 15 but you lost 35hp.", 10);
		Player.changeHealth(-35);
		Player.changeDamage(15);
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 4)
	{
		slowPrint("The star eh? Interesting choice. May the stars guide you on this journey.", 10);
		slowPrint("The stars embrace you in a warm hug.", 10);
		slowPrint("Your health has been restored by 15 points.", 10);
		Player.changeHealth(15);
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 5)
	{
		slowPrint("The moon? Loved for its glow yet cautioned about its dark side.", 10);
		slowPrint("You feel stronger than before but you also sense a loss of vitality.", 10);
		slowPrint("Your attack has increased by 5 but you lost 10hp.", 10);
		Player.changeMaxHealth(-10);
		Player.changeDamage(5);
		Player.setEventLock(true);
		_getch();

	}
	else {

	}
}

void  Event::event_Goddess(Player& Player)//Cannot repeat more than once
{
	int choice;//1-4
	slowPrint("A goddess appears before you. My dear adventurer, your journey has been long, may I offer you a blessing to aid you in this journey?", 10);
	std::cout << "1.Blessing of the Forest" << std::endl;// Restores player to max hp
	std::cout << "2.Blessing of the River" << std::endl;//Player gains 3 HP Potions
	std::cout << "3.Blessing of the Moon" << std::endl;//Player gains an increase attack by 10 points
	std::cin >> choice;
	if (choice == 1)
	{
		slowPrint("The forest spirits prance and dance around you showering you with vitality", 10);
		Player.changeHealth(200);
		_getch();

		//restores 200hp
		Player.setEventLock(true);
	}
	if (choice == 2)
	{

		slowPrint("The river spirits prance and dance around you gifting you 3 Health Potions ", 10);
		Player.addConsumable("Health Potion");
		Player.addConsumable("Health Potion");
		Player.addConsumable("Health Potion");
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 3)
	{
		slowPrint("You feel a surge in strength like never before. Your attack has increased by 10 points ", 10);
		Player.changeDamage(10);
		Player.setEventLock(true);
		_getch();

	}
	else {

	}
}

void  Event::event_DevilsDeal(Player& Player)//Cannot repeat more than once
{
	char option;//Y(es)/ N(o)
	slowPrint("You enter a room, filled with an ominouse presence you then see a name plate reading,", 10);
	slowPrint("The Devil. You then hear.. Tell me mortal, would you like to make a deal with the devil himself?", 10);
	std::cout << "Y/N" << std::endl;
	std::cin >> option;
	if (option == 'Y' || option == 'y')
	{
		Player.setEventLock(true);
		int choice;
		std::cout << "1.Make an investment ( 90% to double the gold you have 10% to lose it all)" << std::endl;
		std::cout << " 2.Keep what you have." << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			RandomNumGenerator numgen;
			int rngNum6 = numgen.getRandomNum(1, 100);
			if (rngNum6 >= 1 && rngNum6 <= 90)
			{
				char option;
				slowPrint("You doubled your money!!", 10);
				Player.gainMoney(Player.getMoney());
				std::cout << "Continue? Y/N (The odds is now 60/40)" << std::endl;
				std::cin >> option;
				if (option == 'Y' || option == 'y')
				{
					RandomNumGenerator numgen;
					int rngNum7 = numgen.getRandomNum(1, 100);
					if (rngNum7 >= 1 && rngNum7 <= 60)
					{
						slowPrint("You doubled your money!!", 10);
						Player.gainMoney(Player.getMoney());
						std::cout << "Continue? Y/N (The odds is now 20/80)" << std::endl;
						std::cin >> option;
						if (option == 'Y' || option == 'y')
						{
							RandomNumGenerator numgen;
							int rngNum8 = numgen.getRandomNum(1, 100);
							if (rngNum8 >= 1 && rngNum8 <= 20)
							{
								slowPrint("You doubled your money!!", 10);
								Player.gainMoney(Player.getMoney());
								slowPrint("Alright that is enough for you. GET OUTTT!!", 10);
								_getch();

							}
							if (rngNum8 >= 21 && rngNum8 <= 100)
							{
								slowPrint("You lost all your money!!", 10);
								Player.loseMoney(Player.getMoney());
								_getch();

							}
						}
						if (option == 'N' || option == 'n')
						{
							slowPrint(" Hmmmm, good choice. Now, GET OUT!!!", 10);
							_getch();

						}

					}
					if (rngNum7 >= 61 && rngNum7 <= 100)
					{
						slowPrint("You lost all your money!!", 10);
						Player.loseMoney(Player.getMoney());
						_getch();

					}

				}
				if (option == 'N' || option == 'n')
				{
					slowPrint(" Hmmmm, good choice. Now, GET OUT!!!", 10);
					_getch();

				}
				else {

				}
			}
			if (rngNum6 >= 90 && rngNum6 <= 100)
			{
				slowPrint("You lost all your money!!", 10);
				Player.loseMoney(Player.getMoney());
				_getch();

			}
		}

		if (choice == 2)
		{
			slowPrint(" Hmmmm, good choice. Now, GET OUT!!!", 10);
			_getch();

		}
		else {

		}

	}
	if (option == 'N' || option == 'n')
	{
		slowPrint("You remember what the folks said. Do not deal with the devil as you walk out of the office.", 10);
		_getch();

	}
	else {

	}
}

void  Event::event_HealthForCash(Player& Player)
{
	int choice;
	slowPrint("\u201c Well it has been a while since I saw an adventurer like yourself.", 10);
	slowPrint("\I am offering you a little money but for in exchange, your health only if you would like, of course.\u201d", 10);
	std::cout << "1.Large amount of money (-50hp)" << std::endl;
	std::cout << "2.A safe amount of money (-35hp)" << std::endl;
	std::cout << "3.A small sum of money (-15hp)" << std::endl;
	std::cout << "4.No thanks" << std::endl;
	std::cin >> choice;
	if (choice == 1)
	{
		slowPrint("Well a big risk taker we have here ay. Well no matter here is the money.", 10);
		slowPrint("As you take the money you feel a great amount of your life force leaving your body.", 10);
		Player.gainMoney(400);
		Player.changeHealth(-50);
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 2)
	{
		slowPrint("Ah the better of both worlds. Good choice here is the money my friend.", 10);
		slowPrint("As you take the money you feel a decent amount of your life force leaving your body.", 10);
		Player.gainMoney(150);
		Player.changeHealth(-35);
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 3)
	{
		slowPrint("A safer option, interesting choice my friend. I hope this amount be deemed enough for your adventure", 10);
		slowPrint("As you take the money you feel a small amount of your life force leaving your body.", 10);
		Player.gainMoney(80);
		Player.changeHealth(-15);
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 4)
	{
		slowPrint("Not a risk taker ay? Well, you know who to look out for if you ever find yourself in poverty.", 10);
		_getch();

	}
	else {

	}
}

void  Event::event_DatingSim(Player& Player)
{
	int choice;
	slowPrint("A girl in a mask stands right in front of your path.", 10);
	slowPrint("Do you think I am pretty?", 10);
	std::cout << "1.Yes" << std::endl;
	std::cout << "2.No" << std::endl;
	std::cout << "3.Do you think I'm pretty?!" << std::endl;
	std::cin >> choice;
	if (choice == 1)
	{
		int choice;
		slowPrint("The lady takes off her mask revealing a slit, blood dripping mouth. WHAT ABOUT NOW?! ", 10);
		std::cout << "1.Yes?" << std::endl;
		std::cout << "2.No" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			slowPrint("You lie. I can sense it. I knew it you always thought I was ugly. DIDNT YOU?!", 10);
			slowPrint("The lady takes out a scissor charging at you and slashes you a couple of time before disappearing. ", 10);
			Player.changeHealth(-10);
			//( Player takes 10hp dmg)
			Player.setEventLock(true);
			_getch();

		}
		if (choice == 2)
		{
			slowPrint("YOURE JUST LIKE ALL OF THEM! YOU PEOPLE NEVER UNDERSTAND!!", 10);
			slowPrint("The lady takes out a scissor charging at you and stabs you before disappearing in black smoke. ", 10);
			Player.changeHealth(-50);
			//( Player takes 50hp dmg)
			Player.setEventLock(true);
			_getch();

		}
		else {

		}
	}
	if (choice == 2)
	{
		slowPrint("Brave of you to say so. ", 10);
		slowPrint("The lady charges at you with a scissor and slashes you. ", 10);
		Player.changeHealth(-15);
		// ( Player takes 15hp damage)
		Player.setEventLock(true);
		_getch();

	}
	if (choice == 3)
	{
		slowPrint("The lady is confused by your question leaving you an opportunity to get away. ", 10);
		Player.setEventLock(true);
		_getch();

	}
	else {

	}
}

void  Event::event_FourthWall(Player& Player)//An occurence to jst make the game a little entertaining
{
	int choice;
	slowPrint("A guy in a black and red mask approaches you. HEY YOU, PLAYER BEHIND THIS SCREEN! WANNA KNOW SOME ###### COOL FACTS ABT THIS GAME?!", 10);
	slowPrint("Our dear friend was orignally designed to one shot players like YOU!", 10);
	slowPrint("The Jonkler, loves to pull magic tricks but so far he only mastered coin pulling, LOL.", 10);
	slowPrint("Teto used to be a part of this game but ever since Miku came along she was never seen again.", 10);
	slowPrint("For some random reason Fatalis somehow managed to enter this place and now I keep hearing BLOODY boss music.", 10);
	std::cout << "1.Thanks for the facts??" << std::endl;
	std::cin >> choice;

	if (choice == 1)
	{
		slowPrint("NO, THANK YOU FOR LISTENING TO MY RAMBLE!! TIME TO BOUNCE, BUT HERE IS A LITTLE SOMETHING FOR YOUR TROUBLES ", 10);
		slowPrint("DO NOT WORRY MARY PUPPINS!! PaPa is COMING HOME. WHOOO!! (if you get the reference, Dam!!)", 10);
		slowPrint("he hands you a bag of money and a note, Bomba was a supposed descendant of god.", 10);
		slowPrint("Oh and by the way heres a GOLDEN TURD I found. You WONT needing this trust me", 10);
		Player.gainMoney(250);
		Player.setEventLock(true);
		Player.addConsumable("GOLDEN TURD");
		_getch();

	}
	else {

	}

}
