#pragma once
#include<iostream>
#include<string>
using namespace std;                                                                                                                                                                                                                                                                                             

class Test
{
public:
	int vPos;
	int hPos;
	void changePos(Test enemy);
	Test(int vertPos = 24, int horPos = 53);
	void attack();
};


