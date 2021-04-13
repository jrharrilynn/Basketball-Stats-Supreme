//-------------------------------------
//                  class Player
//-------------------------------------
// Implements a class that holds the statistics
// for different types of goals and methods to set and get. 
//-------------------------------------



#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "Statistic.h"
const int maxGames = 15;
class player {
private:
	string name;
	string jerNum;
	int gamesPlayed;
	Statistics threePt[maxGames];
	Statistics twoPt[maxGames];
	Statistics freeThrows[maxGames];
	int index;
public:
	player();
	string getName();
	string getjerNum();
	int getGames();
	void setjerNum(string newNum);
	void setGames(int newNum);
	void setName(string newName);
	int threesMade();
	int ThreesAttempted();
	int twosMade();
	int twosAttempted();
	int freesMade();
	int freesAttempted();
	void print();
	int calcTotal();
	void printThree();
	void printTwos();
	void printFrees();
	void setThreesMade(int newVal);
	void setThreesAttempted(int newVal);
	void setTwosMade(int newVal);
	void setTwosAttempted(int newVal);
	void setFreesMade(int newVal);
	void setFreesAttempted(int newVal);
	void setIndex(int index);
	int getIndex();
	int getThM();
	int getThA();
	int getTM();
	int getTA();
	int getFM();
	int getFA();
};