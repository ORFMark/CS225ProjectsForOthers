//Created by: Andrew Kish

#include<iostream>
#include<string>
#include <ctime>
#include "Stock.h"
using namespace std;

void fight(Stock &player, Stock &enemy)
{
	srand(time(NULL));

	bool fight = true; //when one of the fighters dies, this will be set to false, stopping the fight
	bool failure = true; //used if the player dies

	string character = "|C"; //used to represent the characters position on the grid
	string monster = "|M"; //represents monsters positions on the grid
	string row = "_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_"; //used to construct the grid, this is the default row
	string bottomRow = " | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |"; //bottom row of the grid
	string refill = "|_"; //used to refill spots on the grid taken by the character and the monster

	while (fight == true) //this whole loop handles the actual battle and grid generation
	{
		string rowChar = row; //row that will contain the character. this and rowMon are here to reset the row to empty every loop, so that the chaaracter and monster symbols only appear once
		string rowMon = row; //row that will contain the monster

		rowChar.replace(player.hPos, 2, character); //places the character symbol inside the row
		rowMon.replace(enemy.hPos, 2, monster);


		//This for loop creates the grid
		for (int i = 0; i < 52; i++)
		{
			if (player.vPos == enemy.vPos) //this checks whether the player and monster are on the same row, if they are it adds the monster to the character row, so they both display
			{
				rowChar.replace(enemy.hPos, 2, monster);
			}
			if (i == player.vPos) //this checks where the player's row is, and prints it out when the grid reaches it
			{
				cout << rowChar << endl;
			}
			else if (i == enemy.vPos) //this checks where the monster's row is, and prints it out when the grid reaches it
			{
				cout << rowMon << endl;
			}
			else if (i == 51) //this causes the bottom row to print out at the bottom of the grid
			{
				cout << bottomRow << endl;
			}
			else //if no other row is printed, this prints the default row
			{
				cout << row << endl;
			}
		}
		fight = player.changePos(enemy);

		if (fight == true)
		{
			try
			{
				enemy.monMove(player);
			}
			catch (bool continueFight)
			{
				throw failure;
			}
		}
		system("CLS"); //#clears the screen
	}
}