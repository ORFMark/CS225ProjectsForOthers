//Created by: Patrick McDoniel and Andrew Kish

#include<iostream>
#include<string>
#include<windows.h> //needed for Sleep
#include<math.h> //needed for pow
#include "Stock.h"
using namespace std;

Stock::Stock(int maxHealth, int armorClass, int prof, int accuracy, int damageDie, int damageBonus, int vertPos, int horPos, int range) //constructor for Stock
{
	stat.maxHealth = maxHealth;
	stat.health = maxHealth;
	stat.armorClass = armorClass;
	stat.prof = prof;
	stat.accuracy = accuracy;
	stat.damageDie = damageDie;
	stat.damageBonus = damageBonus;
	vPos = vertPos;
	hPos = horPos;
	stat.range = range;
}


NPC::NPC(int maxHealth, int armorClass, int prof, int accuracy, int damageDie, int damageBonus, int vertPos, int horPos, int range, string Cdialogue, string Creply1, string Creply2, string Creply3, string Cresult1, string Cresult2, string Cresult3, int Copinion) //constructor for NPC
{
	stat.maxHealth = maxHealth;
	stat.health = maxHealth;
	stat.armorClass = armorClass;
	stat.prof = prof;
	stat.accuracy = accuracy;
	stat.damageDie = damageDie;
	stat.damageBonus = damageBonus;
	vPos = vertPos;
	hPos = horPos;
	stat.range = range;
	dialogue = Cdialogue;
	reply1 = Creply1;
	reply2 = Creply2;
	reply3 = Creply3;
	result1 = Cresult1;
	result2 = Cresult2;
	result3 = Cresult3;
	opinion = Copinion;
	encounter();
}

void NPC::encounter() 
{
	cout << dialogue << endl; //prints npc dialogue upon encounter
	cout << "The reply options are: " << endl << "1: " << reply1 << endl << "2: " << reply2 << endl <<  "3: " << reply3 << endl; //shows player possible replies
	int choice; //used to allow player to choose response
	cout << "Enter the number for the reply you want to enter: ";
	cin >> choice;
	if (choice == 1) //this if statement sets the npc opinion based on player response
		results(result1);
	else if (choice == 2)
		results(result2);
	else if (choice == 3)
		results(result3);
}

void NPC::results(string result) 
{
	if (result == "good")
		opinion = 1;
	if (result == "neutral")
		opinion = 0;
	if (result == "bad")
		opinion = -1;
}

void Stock::changeHealth(int damage)
{
	stat.health = stat.health - damage; //subtracts damage done from current health (- damage heals)
}

void Stock::setStats(int maxHealth, int armorClass, int prof, int accuracy, int damageDie, int damageBonus, int vertPos, int horPos, int range) //sets stats for Stock
{
	stat.maxHealth = maxHealth;
	stat.health = maxHealth;
	stat.armorClass = armorClass;
	stat.prof = prof;
	stat.accuracy = accuracy;
	stat.damageDie = damageDie;
	stat.damageBonus = damageBonus;
	vPos = vertPos;
	hPos = horPos;
	stat.range = range;
}

int Stock::attack(Stock opponent)
{
	int toHit; //roll used to determine if an attack lands
	int damage; //amount of damage done

	toHit = rollDie20() + stat.accuracy; //gets a random number from 1 to 20, and adds the accuracy of attacker

	//this series of if statements finds a random value for damage based on die type, also adds a flat damage bonus
	if (stat.damageDie = 4) 
	{
		damage = rollDie4() + stat.damageBonus;
	}
	else if (stat.damageDie = 6)
	{
		damage = rollDie6() + stat.damageBonus;
	}
	else if (stat.damageDie = 8)
	{
		damage = rollDie8() + stat.damageBonus;
	}
	else if (stat.damageDie = 10)
	{
		damage = rollDie10() + stat.damageBonus;
	}
	else if (stat.damageDie = 12)
	{
		damage = rollDie12() + stat.damageBonus;
	}

	if (toHit >= opponent.stat.armorClass) //determines whether an attack hits, if the toHit value matches or exceeds the targets armor class, they hit
	{
		cout << "hit for " << damage << " damage!" << endl; //displays damage dealt
		Sleep(500); //pauses so player can see damage result
		return damage; //returns the damage value, to be used as an input for the changeHealth function
	}
	else
	{
		cout << "missed." << endl; //informs player that they missed
		Sleep(500); //pauses so player can see result of attack
		return 0; //returns the damage value (0, since they missed), to be used as an input for the changeHealth function
	}
}

bool Stock::changePos(Stock &enemy)
{
	string direction; //used as input for direction of movement
	bool error = false; //used to check for unacceptable inputs
	bool inRange = false; //used to check the the enemy is in range of the player's attack
	bool fight = true; //used to check if fight has ended

	double hDis = (hPos - enemy.hPos)/2; //calculates horizontal distance from player to enemy, divided by 2 to account for each horizontal square taking 2 characters
	double vDis = vPos - enemy.vPos; //calculates vertical distance from plaer to enemy
	double dis = sqrt(pow(hDis, 2) + pow(vDis, 2)); //calculates general distance from player to enemy

	if (dis <= stat.range) //if the enemy is in range of player's attacks, sets the inRange variable to true
	{
		inRange = true;
	}

	int tempV = vPos; //temporary vertical position, this and tempH are used to prevent the player and enemy from being on the same square
	int tempH = hPos; //temporary horizontal position
	cout << "Your health is: " << stat.health << "/" << stat.maxHealth << endl; //displays player health
	do
	{
		error = false; //assumes that there is no error
		cout << "What direction do you want to move? (w for up, a for left, d for right, s for down"; //prompts player for direction  input
		if (inRange == true) //if the enemy is in range of player's attack, adds additional prompt to attack enemy
		{
			cout << ", attack to attack your enemy): ";
		}
		else //default end of prompt if not in range
		{
			cout << "): ";
		}
		cin >> direction; //accepts an input for the direction
		if (((direction != "w") & (direction != "a") & (direction != "s") & (direction != "d") & (direction != "attack")) | ((direction == "attack") & (inRange == false))) //checks if the input for direction is not one of the accepted options
		{
			error = true;
			cout << "Improper direction choice, try again." << endl;
		}
	} while (error == true);

	if (direction == "w") //moves the player up on the grid
	{
		vPos--;
	}
	else if (direction == "s") //moves the player down on the grid
	{
		vPos++;
	}
	else if (direction == "d") //moves the player left on the grid
	{
		hPos += 2;
	}
	else if (direction == "a") //moves the player right on the grid
	{
		hPos -= 2;
	}
	else if ((direction == "attack") & (inRange == true)) //allows player to attack if in range
	{
		cout << "You "; //used when printing damage done
		enemy.changeHealth(attack(enemy)); //runs attack function and inputs the result to the changeHealth function
		if (enemy.stat.health < 1) //checks if monster has died, ends fight if it is
		{
			cout << "You win good job" << endl;
			Sleep(500);
			fight = false;
		}
		else if (enemy.stat.health > enemy.stat.maxHealth) //prevents any sort of error allowing the player to have more than maximum health
		{
			stat.health = stat.maxHealth;
		}
	}
	//this set of if/else statements prevents the player from leaving the grid
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

	if ((vPos == enemy.vPos) & (hPos == enemy.hPos)) //causes the player to attack the monster if they move onto the same square
	{
		cout << "You ";
		enemy.changeHealth(attack(enemy));
		if (enemy.stat.health < 1)
		{
			cout << "You win good job" << endl;
			Sleep(500);
			fight = false;
			throw fight;
		}
		else if (enemy.stat.health > enemy.stat.maxHealth)
		{
			stat.health = stat.maxHealth;
		}
		hPos = tempH; //this and the next line prevent the player and enemy from occupying the same square
		vPos = tempV;
	}
	return fight;
}

void Stock::monMove(Stock &player)
{
	//variables hold same function as in changePosition
	bool inRange = false;
	double hDis = (hPos - player.hPos) / 2;
	double vDis = vPos - player.vPos;
	double dis = sqrt(pow(hDis, 2) + pow(vDis, 2));

	if (dis <= stat.range)
	{
		inRange = true;
	}

	int tempV = vPos;
	int tempH = hPos;

	if (inRange == true) //attacks player if they are in the monster's range
	{
		cout << "Enemy ";
		player.changeHealth(attack(player));
		bool fight = true;
		if (player.stat.health < 1) //checks if player has died, if so ends the fight
		{
			fight = false;
			throw fight;
		}
		else if (player.stat.health > player.stat.maxHealth)
		{
			stat.health = stat.maxHealth;
		}
	}
	//if the enemy can't attack, this block of if/else statements checks the fastest way to get to the player and moves towards them
	else if ((hDis > vDis) & (hDis > 0))
	{
		hPos-=2;
	}
	else if ((hDis < vDis) & (hDis < 0))
	{
		hPos+=2;
	}
	else if ((vDis >= hDis) & (vDis > 0))
	{
		vPos--;
	}
	else if ((vDis >= hDis) & (vDis < 0))
	{
		vPos++;
	}
	if ((hPos == player.hPos) & (vPos == player.vPos)) //prevents enemy and player from occupyng the same square
	{
		hPos = tempH;
		vPos = tempV;
	}
}

Stock operator>>(istream &is, Stock &s)
{
	cout << "Warning, this is intended for testing use only and will allow you to make a character so powerful as to make the game trivial." << endl;
	int maxHealth, armorClass, prof, accuracy, damageDie, damageBonus, range;
	cout << "Enter your maximum health: ";
	cin >> maxHealth;
	cout << "Enter your armor class: ";
	cin >> armorClass;
	cout << "Enter your proficiency bonus: ";
	cin >> prof;
	cout << "Enter your accuracy: ";
	cin >> accuracy;
	do
	{
		cout << "Enter your damage die (4, 6, 8, 12, or 20): ";
		cin >> damageDie;
	} while ((damageDie != 4) & (damageDie != 6) & (damageDie != 8) & (damageDie != 12) & (damageDie != 20));
	cout << "Enter your damage bonus: ";
	cin >> damageBonus;
	cout << "Enter your range in squares: ";
	cin >> range;
	s.setStats(maxHealth, armorClass, prof, accuracy, damageDie, damageBonus, 24, 53, range);
	return s;
}