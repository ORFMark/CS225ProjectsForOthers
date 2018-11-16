//Created by: Patrick McDoniel

#include <iostream>
using namespace std;

int rollDie4()
{
	int roll4;
	int min = 1; // the min number a die can roll is 1
	int max = 4; // the max value is the die size

	roll4 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll4;
}

int rollDie6()
{
	int roll6;
	int min = 1; // the min number a die can roll is 1
	int max = 6; // the max value is the die size

	roll6 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll6;
}

int rollDie8()
{
	int roll8;
	int min = 1; // the min number a die can roll is 1
	int max = 8; // the max value is the die size

	roll8 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll8;
}

int rollDie10()
{
	int roll10;
	int min = 1; // the min number a die can roll is 1
	int max = 10; // the max value is the die size

	roll10 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll10;
}

int rollDie12()
{
	int roll12;
	int min = 1; // the min number a die can roll is 1
	int max = 12; // the max value is the die size

	roll12 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll12;
}

int rollDie20()
{
	int roll20;
	int min = 1; // the min number a die can roll is 1
	int max = 20; // the max value is the die size

	roll20 = rand() % (max - min + 1) + min; //generates a random number between max and min values

	return roll20;
}