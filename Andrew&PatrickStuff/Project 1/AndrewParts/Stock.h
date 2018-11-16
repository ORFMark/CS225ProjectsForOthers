//Created by: Patrick McDoniel and Andrew Kish

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include "DiceRoll.h"
using namespace std;

struct Stats
{
	int maxHealth; //maximum health
	int health; //current health
	int armorClass; //armor class, how hard it is to hit them with an attack
	int prof; //proficiency, a general bonus added to several things
	int accuracy; //how likely they are to hit when attacking
	int damageDie; //what type of die they roll for damage
	int damageBonus; //flat bonus added to damage
	int range; //how far away they can attack from
};

class Stock
{
protected:
	Stats stat;
public:
	int vPos; //vertical position on grid
	int hPos; //horizontal position on grid
	bool changePos(Stock &enemy); //moves the player
	void monMove(Stock &player); //moves the monster
	void changeHealth(int damage); //changes current health
	int attack(Stock opponent); //calculates whether or not an attack hits, as well as how much damage it does
	void setStats(int maxHealth, int armorClass, int prof, int accuracy, int damageDie, int damageBonus, int vertPos, int horPos, int range); //changes all stats
	friend Stock operator>>(istream &is, Stock &s); //used for custom character creation
	Stock(int maxHealth = 0, int armorClass = 0, int prof = 0, int accuracy = 0, int damageDie = 0, int damageBonus = 0, int vertPos = 24, int horPos = 53, int range = 1); //constructor intializer
	~Stock() { cout << ""; }
};


class NPC : public Stock //Non-Player Character, child of stock
{
private:
	string dialogue; //what they say upon first contact
	string reply1; //1st possible reply by player
	string reply2;//2nd possible reply by player
	string reply3;//3rd possible reply by player
	string result1; //result if 1st reply chosen
	string result2; //result if 2nd reply chosen
	string result3; //result if 3rd reply chosen
public:
	int opinion; //represents npc opinion of player (-1 is bad, 0 is nuetral, 1 is good)
	void encounter(); //called upon meeting the npc, handles the conversation and begins combat, if necessary
	void results(string result); //calculates the opinion of npc based on encounter with player
	NPC(int maxHealth, int armorClass, int prof, int accuracy, int damageDie, int damageBonus, int vertPos, int horPos, int range, string dialogue, string reply1, string reply2, string reply3, string result1, string result2, string result3, int opinion); //constructor intializer for npc
} ;


//C for character, M for monster, enter under the grid
