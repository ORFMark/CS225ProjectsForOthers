#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

Test::Test(int vertPos, int horPos)
{
	vPos = vertPos;
	hPos = horPos;
}

void Test::attack()
{
	cout << "You hit!";
}

void Test::changePos(Test enemy)
{
	string direction;
	cout << "What direction do you want to move? (w for up, a for left, d for right, s for down): ";
	cin >> direction; //accepts an input for the direction

	//thow an exception here if they input an unexceptable direction

	//changes direction based on input
	if (vPos == enemy.vPos & hPos == enemy.hPos)
	{
		attack();
	}
	else
	{
		if (direction == "w")
		{
			vPos--;
		}
		else if (direction == "s")
		{
			vPos++;
		}
		else if (direction == "d")
		{
			hPos += 2;
		}
		else if (direction == "a")
		{
			hPos -= 2;
		}

		if (vPos <= 0)
		{
			vPos = 1;
		}
		else if (vPos >= 51)
		{
			vPos = 50;
		}
		else if (hPos <= 0)
		{
			hPos = 1;
		}
		else if (hPos >= 103)
		{
			hPos = 101;
		}
	}
}