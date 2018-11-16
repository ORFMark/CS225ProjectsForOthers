//Created by: Patrick McDoniel and Andrew Kish

#include<iostream>
#include<string>
#include<windows.h> //needed for Sleep
#include<fstream>
#include "Stock.h"
using namespace std;

void fight(Stock &player, Stock &enemy); //creates combat grid and handles all acutal fighting

int main()
{
	cout << "In combat, you are represented by the C, and your enemy is represented by the M" << endl << "It is recommended you set this window to full screen" << endl;

	int slain = 0; //represents how many enemies you have slain
	string person; //input for character choice
	Stock player; //object of class Stock that will represent the player
	bool creation = true; //used to error check character choice

	while (creation == true) //has the player choose which character they will play as
	{
		cout << "What kind of fighter are you? (knight, wizard, cleric, ranger, custom): ";
		cin >> person;
		if (person == "knight") 
		{
			cout << "The archtypical knight, you have a sword, a shield, and you bash monsters in the head with them." << endl;
			player.setStats(50, 22, 2, 6, 12, 4, 24, 53, 1);
			creation = false;
		}
		else if (person == "wizard") 
		{
			cout << "The mysterious wizard, you control magic beyond even your own understanding, good luck." << endl;
			player.setStats(16, 16, 2, 6, 20, 0, 24, 53, 24);
			creation = false;
		}
		else if (person == "cleric") 
		{
			cout << "The devout cleric, you call down holy retribution against the enemies of your god." << endl;
			player.setStats(26, 18, 2, 4, 6, 2, 24, 53, 12);
			creation = false;
		}
		else if (person == "ranger") 
		{
			cout << "The ranger, you shoot people with your bow. Congratulations on choosing the best class." << endl;
			player.setStats(20, 16, 2, 6, 8, 4, 24, 53, 30);
			creation = false;
		}
		else if (person == "custom")
		{
			cin >> player;
			creation = false;
		}
		else
		{
			cout << "Choice failed, try again" << endl; //displayed if player made an unacceptable choice
		}
	}

	cout << "A goblin has snuck up behind you and has begun attacking, defend yourself!" << endl;
	Stock goblin;
	goblin.setStats(6, 14, 2, 4, 6, 2, 31, 61, 1);
	try
	{
		fight(player, goblin);
	}
	catch (bool failure)
	{
		if (failure == true)
		{
			cout << "You have died, game over.";
			Sleep(1000);
			return 0;
		}
	}
	slain++;
	cout << "The goblin is defeated. It's unusual for such a weak creature to attack someone like you, perhaps something has riled the weaker monsters up?" << endl;

	NPC merchant(10, 16, 2, 6, 8, 3, 20, 61, 30, "Greetings traveler, how fairs the road?", "Nothing unusual", "I've encountered bold monster, watch your back.", "You're about to find out just how bad, unless you hand over your goods.", "nuetral", "good", "bad", 0);
	if (merchant.opinion == -1)
	{
		try
		{
			fight(player, merchant);
		}
		catch (bool failure)
		{
			if (failure == true)
			{
				cout << "You have died, game over.";
				Sleep(1000);
				return 0;
			}
		}
		cout << "So that's what kind of person your are. Well, you've successfully robbed him. Additionally you find a healing potion and drink it." << endl;
		player.changeHealth(-4);
		slain++;
	}
	if (merchant.opinion == 1)
	{
		cout << "Thanks for the warning, have this potion, I have plenty." << endl << "You drink the potion" << endl;
		player.changeHealth(-4);
	}

	Stock hob;
	hob.setStats(25, 14, 2, 5, 10, 6, 20, 57, 1);
	cout << "Another ambush? Looks like this one is bigger." << endl;
	try
	{
		fight(player, hob);
	}
	catch (bool failure)
	{
		if (failure == true)
		{
			cout << "You have died, game over.";
			Sleep(1000);
			return 0;
		}
	}
	cout << "You beat this one too, but he was definetely stronger than the last one." << endl;

	cout << "After traveling for some time you find yourself approaching a city." << endl;

	NPC guard(20, 18, 2, 6, 10, 4, 21, 41, 1, "Halt, what business do you have in the city?", "I'm here to kill and rob everyone I find.", "Just passing through.", "I'm investigating some particularly agressive goblins, and was hoping to find information in this city.", "bad", "neutral", "good", 0);
	if (guard.opinion == -1)
	{
		try
		{
			fight(player, guard);
		}
		catch (bool failure)
		{
			if (failure == true)
			{
				cout << "You have died, game over.";
				Sleep(1000);
				return 0;
			}
		}
		cout << "You've successfully killed your way into the city, good job I guess?" << endl;
		slain++;
	}
	if (guard.opinion == 1)
	{
		cout << "You should check out the Flipping Harpy tavern, adventurers tend to gather there. Tell them Henry sent you" << endl;
	}
	cout << "After wandering for some time you manage to find the tavern. It's filled with racous adventurers, maybe they know what's going on with the goblins." << endl;
	if (guard.opinion == 1)
	{
		cout << "You approach the barkeep and tell him Henry sent you." << endl << "Henry sent you did he? That's out of character, well, he probably had good reason. Goblins, eh? I'd recommend asking around with the other adventurers to see of they know what's going on. Also, feel free to take the last room on the left upstairs." << endl;
		player.changeHealth(-25);
	}
	cout << "After resting up and asking around it seems that you've found a wizard who seems to know something of what's going on." << endl;

	NPC wizard(15, 12, 3, 8, 10, 8, 21, 43, 10, "Goblins causing trouble again? They probably found themselves another leader. They usually manage to collect some good loot. If you don't handle it I'm sure someone else will come along, but you could do a lot of good by taking it down.", "Thanks for the help, I'll head right out.", "Good loot, sounds like my kind of adventure, see ya later.", "Loot you say? Can't let word of that get out before I take it.", "good", "neutral", "bad", 0);
	if (wizard.opinion == -1)
	{
		try
		{
			fight(player, wizard);
		}
		catch (bool failure)
		{
			if (failure == true)
			{
				cout << "You have died, game over.";
				Sleep(1000);
				return 0;
			}
		}
		cout << "Another corpse for the list then." << endl;
		slain++;
	}
	if (wizard.opinion == 1)
	{
		cout << "Hmmm, before you go, let me enchant your weapon. You look like you could use the help." << endl;
		if (person == "knight") 
		{
			player.setStats(50, 22, 2, 7, 12, 5, 24, 53, 1);
		}
		else if (person == "wizard") 
		{
			player.setStats(16, 16, 2, 7, 20, 1, 24, 53, 24);
		}
		else if (person == "cleric") 
		{
			player.setStats(26, 18, 2, 5, 6, 3, 24, 53, 12);
		}
		else if (person == "ranger") 
		{
			player.setStats(20, 16, 2, 7, 8, 5, 24, 53, 30);
		}
	}

	cout << "You've managed to find your way to monsters' lair, a dark cave sinking deep into a hill. What terrors lurk within?" << endl << "Entering the cave, you suddenly hear the sound of falling rocks, it's a trap!" << endl;
	if (person == "knight") 
	{
		cout << "You manage to deflect most of the falling rocks with your shield, but got a couple bruises in the process." << endl;
	}
	else if (person == "wizard") 
	{
		cout << "You blast the rocks with destructive magic before they are able to strike you, that was a close one." << endl;
	}
	else if (person == "cleric") 
	{
		cout << "Through the will of your god, you managed to raise a magical barrier to protect yourself." << endl;
	}
	else if (person == "ranger") 
	{
		cout << "Fortunately, you noticed this trap well before it was actually sprung on you. Nimbly stepping to the side, you avoid all the rocks." << endl;
	}

	cout << "Finally you've made it to the bottom of this cave, the last obstacle is a door, guarded by an overweight ogre." << endl;
	Stock ogre;
	ogre.setStats(35, 14, 3, 6, 10, 6, 19, 43, 1);
	try
	{
		fight(player, ogre);
	}
	catch (bool failure)
	{
		if (failure == true)
		{
			cout << "You have died, game over.";
			Sleep(1000);
			return 0;
		}
	}
	cout << "The beast is dead, now you can finally discover what the leader of these things is." << endl;
	slain++;

	cout << "Upon opening the door, you see what appears to be a human, sitting on a throne made of stone." << endl << "The warrior, clad in black armor, rises to greet you, and slowly bows." << endl << "Well done, I wasn't expecting anyone to discover my plans so quickly, unfortunately you cannot hope to defeat me." << endl << "The monsters' leader draws a clearly magical sword and begins to advance towards you." << endl;
	Stock boss;
	boss.setStats(35, 18, 4, 8, 12, 6, 17, 33, 1);
	try
	{
		fight(player, boss);
	}
	catch (bool failure)
	{
		if (failure == true)
		{
			cout << "You have died, game over.";
			Sleep(1000);
			return 0;
		}
	}
	cout << "The dark warrior has fallen, you collect your loot and head out, secure in the knowledge that this group of monsters won't be causing anyone any more trouble." << endl;
	slain++;

	ofstream fout("FinalStats.txt");
	fout << "Congratulations, you've won, you killed " << slain << " enemies" << endl;
	if (slain == 4)
	{
		fout << "This is the least life it is possible to take in this game and win, good job." << endl;
	}
	else if (slain >= 6)
	{
		fout << "You killed everyone you could, you absolute monster." << endl;
	}

	return 0;
}