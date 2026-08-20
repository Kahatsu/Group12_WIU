#include "Event.h"
#include <iostream>
#include <ctime>
#include "RandomNumGenerator.h"

int main()
{
	srand((unsigned int)time(0));
	RandomNumGenerator numgen;
	int eventNum = numgen.getRandomNum( 1, 10);
	int choice;
	
	switch (eventNum)
	{
	case 1: std::cout << "You approach a fountain containing water that appears to reflect yourself." << std::endl;
		std::cout << "What do you do?" << std::endl;
		std::cout << "Option 1: You take a handful and drink it." << std::endl;
		std::cout << "Option 2: You decide to wash your wounds with the water" << std::endl;
		std::cout << "Option 3: You decide to leave it alone" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "Your attack has been increased by 5%." << std::endl;
		}
		if (choice == 2)
		{
			std::cout << "Your health has been increased by 20." << std::endl;
		}
		if (choice == 3)
		{
			break;
		}
		break;


	case 2: std::cout << "A shrine stands in front of you and at the foot of its entrance a box with a hole just big enough for coins. Will you test your luck with fate? (50 coins) " << std::endl;
			std::cout << "Insert coin"<<std::endl;
			std::cout << "Leave it alone" << std::endl;
		break;

	case 3:std::cout << "A wheel stands before you. Go on adventurer spin it and let fate define your very means" << std::endl;
		 std::cout << "Spin" << std::endl;
		 std::cout << "Don't spin" << std::endl;
		break;

	case 4:std::cout << "You see a pack of bloodhounds chained. Do you:" << std::endl;
		std::cout << "1.Free them" << std::endl;
		std::cout << "2.Leave them alone" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "HEY! MY DOGS!! How dare you defy BobbyTheBandit! Prepare to die!" << std::endl;
		}

		if (choice == 2)
		{
			std::cout << "You leave the vicinity with some guilt in your chest.... Maybe you should have freed them?" << std::endl;
			break;
		}

		break;

	case 5: std::cout << "As you walk further down, you approach a table with tarot cards faced up. “Adventurer, pick a card as you please." << std::endl;
		std::cout << "1.The Fool" << std::endl;
		std::cout << "2.The Emperor" << std::endl;
		std::cout << "3.The Devil" << std::endl;
		std::cout << "4.The Star" << std::endl;
		std::cout << "5.The Moon" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "It is time you let go of your fear and embrace new journeys." << std::endl;
			//Player gains +5 attack but loses 10hp 
		}

		if (choice == 2)
		{
			std::cout << "Now is your moment to seize control of your life with unwavering confidence and authority." << std::endl;
			//Enter battle against 4 goblins
			break;
		}
		if (choice == 3)
		{
			std::cout << "You are called to confront the chains that bind you." << std::endl;
			// Player gains +15 attack but at the cost of 35hp
		}

		if (choice == 4)
		{
			std::cout << "Now is the time to embrace hope and renewal in your life. You should focus on nurturing your dreams and aspirations." << std::endl;
			//Player is healed for 15hp
			break;
		}

		if (choice == 5)
		{
			std::cout << "You are called upon to embrace uncertainty and trust your intuition" << std::endl;
			//Enter a battle against a bomba 
			break;
		}

		

		break;

	case 6:std::cout << "A goddess appears before you,  My dear adventurer, your journey has been long, may I offer you a blessing to aid you in this journey?" << std::endl;
		std::cout << "1.Blessing of the Forest" << std::endl;
		std::cout << "2.Blessing of the River" << std::endl;
		std::cout << "3.Blessing of the Sun" << std::endl;
		std::cout << "4.Blessing of the Moon" << std::endl;
		break;

	case 7:std::cout << " Tell me mortal, would you like to make a deal with the devil himself " << std::endl;
		std::cout << "Make an investment ( 90% to double the gold you have 10% to lose it all)" << std::endl;
		std::cout << "Keep what you have" << std::endl;
		break;

	case 8:std::cout << " Well it has been a while since I saw an adventurer like yourself. I can upgrade your equipment for you if you would like.";
			std::cout << "Yes Please" << std::endl;
			std::cout << "No thanks" << std::endl;
		break;

	case 9:std::cout << "A girl in a mask stands right in front of your path. Do you think I am pretty?" << std::endl;
		break;

	case 10:std::cout << "A guy in a black and red mask ( not deadpool trust ) approaches you. HEY PLAYER BEHIND THIS SCREEN ! HOW ## DO I GET OUT OF THIS #### PLACE?!";
		std::cout << "ARE YOU SPIDERMAN?!" << std::endl;
		std::cout << "YOU ARE THE GUY FROM FORTNITE!!" << std::endl;
		std::cout << "MIND YOUR LANGUAGE" << std::endl;
		break;

	}




	return 0;
}
