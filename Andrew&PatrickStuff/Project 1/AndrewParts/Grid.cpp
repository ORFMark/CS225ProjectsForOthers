#include<iostream>
#include<string>
#include "Header.h"
using namespace std;


int main()
{
	Test abigail;
	Test enemy;
	enemy.changePos(abigail);
	string character = "|C"; //used to represent the characters position on the grid
	string monster = "|M"; //represents monsters positions on the grid
	string row = "_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_"; //used to construct the grid, this is one default row
	string bottomRow = " | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |";
	string refill = "|_";
	bool fight = true;

	//while (fight == true)
	for (int i = 0; i < 40; i++)
	{
		string rowChar = row; //row that will contain the character. this and rowMon are here to reset the row to empty every loop, so that the chaaracter and monster symbols only appear once
		string rowMon = row; //row that will contain the monster

		rowChar.replace(abigail.hPos, 2, character); //places the character symbol inside the row
		rowChar.replace(enemy.hPos, 2, monster);

		//This for loop creates the grid
		for (int i = 0; i < 52; i++)
		{
			if (abigail.vPos == enemy.vPos)
			{
				rowChar.replace(enemy.hPos, 2, monster);
			}
			else
			{
				if (i == abigail.vPos)
				{
					cout << rowChar << endl;
				}
				else if (i == enemy.vPos)
				{
					cout << rowMon << endl;
				}
			}
			else if (i == 51)
			{
				cout << bottomRow << endl;
			}
			else
			{
				cout << row << endl;
			}
		}
		abigail.changePos(enemy);
	}
}