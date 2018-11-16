#include <iostream>
using namespace std;

int rollDie6() {
int roll6;
int min = 1; // the min number a die can roll is 1
int max = 6;// this->dieSize; // the max value is the die size

roll6 = rand() % (max - min + 1) + min;

return roll6;
}
