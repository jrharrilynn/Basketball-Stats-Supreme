//-------------------------------------
//                  class team
//-------------------------------------
// Implements a team of Players and their methods
//-------------------------------------


#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "Statistic.h";
#include "player.h";
#include <fstream>;
const int maxPlayer = 10;

class team {
public:
	team();
	void setPlayers(int newNum);
	void setGames(int newNum);
	int getPlayers();
	int getGames();
	void read();
	void print();
	void addGame();
	void displayPlayer();
	void removePlayer();
	int findPlayer();
	void sortByName();
	void Swap(int& index1, int& index2);
	void sortByJersey();
	void write();
	void addPlayer();
private:
	int numPlayers;
	int numGames;
	player P[maxPlayer];
};