#include <string>
#include<iostream>
using namespace std;
#include "Statistic.h";
#include "player.h";
#include <iomanip>


//initializes the player
player::player() 
{
	name = "NONE";
	jerNum = "";
	gamesPlayed = 0;
}
//get and set methods
string player::getName() 
{
	return name;

};

int player::getGames()
{
	return gamesPlayed;
}

string player::getjerNum()
{
	return jerNum; 
}

void player::setGames(int newNum)
{
	gamesPlayed = newNum;
}

void player::setName(string newName)
{
	name = newName;
}

void player::setjerNum(string newNum)
{
	jerNum = newNum;
}

//calculates the total amount of 3's made
int player::threesMade() {
	int x = getGames();
	int sum3Made = 0;
	for (int i = 0; i < x; i++) {
		sum3Made = sum3Made + threePt[i].getPointsMade();
	}
	return sum3Made;
}

//calculates the total amount of 3's attempted
int player::ThreesAttempted()
{
	int x = getGames();
	int sum3attempted = 0;
	for (int i = 0; i < x; i++) {
		sum3attempted = sum3attempted + threePt[i].getPointsAttempted();
	}
	return sum3attempted;

}

//calculates the total amount of 2's made
int player::twosMade() {
	int x = getGames();
	int sum2Made = 0;
	for (int i = 0; i < x; i++) {
		sum2Made = sum2Made + twoPt[i].getPointsMade();
	}
	return sum2Made;
}


//calculates the total amount of 2's attempted
int player::twosAttempted() {
	int x = getGames();
	int sum2Attempted = 0;
	for (int i = 0; i < x; i++) {
		sum2Attempted = sum2Attempted + twoPt[i].getPointsAttempted();
	}
	return sum2Attempted;
}

//calculates the amount of freethrows made
int player::freesMade() {
	int x = getGames();
	int freesMade = 0;
	for (int i = 0; i < x; i++) {
		freesMade = freesMade + freeThrows[i].getPointsMade();
	}
	return freesMade;
}

//calculates the amount of free throws attempted
int player::freesAttempted() {
	int x = getGames();
	int freesAttempted = 0;
	for (int i = 0; i < x; i++) {
		freesAttempted = freesAttempted + freeThrows[i].getPointsAttempted();
	}
	return freesAttempted;
}

//calculates the total score for the player
int player::calcTotal() {
	int x=freesMade();
	int y = twosMade();
	int z = threesMade();
	int total = x + (y*2) + (z*3);
	return total;
}


//prints the statistics for three pointers
void player::printThree() {
	int x = threesMade();
	int y = ThreesAttempted();
	float perc;
	if (y <= 0) {
		perc = 0;
	}
	else {
		perc = (100 * x / y);
	}
	cout << setw(2) << x << "/" << setw(2) << y << " (" << setw(3) << setprecision(0) << fixed << perc << ")";
}


//prints the statistics for two pointers
void player::printTwos() {
	int x = twosMade();
	int y = twosAttempted();
	float perc;
	if (y <= 0) {
		perc = 0;
	}
	else
	 perc = (100 * x / y);
	cout << setw(2) << x << "/" << setw(2) << y << " (" << setw(3) << setprecision(0) << fixed << perc << ")";
}


//prints the statistics for free throws
void player::printFrees() {
	int x =freesMade();
	int y = freesAttempted();
	float perc;
	if (y <= 0) {
		perc = 0;
	}
	else
	 perc = (100 * x / y);
	cout << setw(2) << x << "/" << setw(2) << y << " (" << setw(3) << setprecision(0) << fixed << perc << ")";
}


// This is an incomplete method to print the PLAYER REPORT
// You are not required to use it, but you may find it helpful
// The MM/AA (NNN%) is 12-characters long
// ALL CAPS are used where you have to "plug in" your own names

void player::print() {
	cout << getName() << "  [" << getjerNum() << "] \n";
	cout << right; // right-justify all numbers in the report
	cout << "Game  3-Point FGs   2-Point FGs   Free Throws   Total\n";
	cout << "----  ------------  ------------  ------------  -----\n";
	for (int i = 0; i < getGames(); i++) {
		cout << setw(4) << (i+1) << "  "; // change i to (i+1) if you like
		 threePt[i].printStats();
		cout << "  ";
		twoPt[i].printStats();
		cout << "  ";
		freeThrows[i].printStats();
		cout << "  " << setw(5) << ((threePt[i].getPointsMade()*3)+(twoPt[i].getPointsMade()*2)+(freeThrows[i].getPointsMade()*1)) << "\n";
	}
	cout << " ALL  ";
	printThree();
	cout << "  ";
	printTwos();
	cout << "  ";
	printFrees();
	cout << "  " << setw(5) << calcTotal() << "\n\n";
} // print()


//set and get methods
void player::setThreesMade(int newVal) {
	threePt[getIndex()].setPointsMade(newVal);
}

void player::setThreesAttempted(int newVal) {
	threePt[getIndex()].setPointsAttempted(newVal);
}

void player::setTwosMade(int newVal) {
	twoPt[getIndex()].setPointsMade(newVal);
}

void player::setTwosAttempted(int newVal) {
	twoPt[getIndex()].setPointsAttempted(newVal);
}

void player::setFreesMade(int newVal) {
	freeThrows[getIndex()].setPointsMade(newVal);

}

void player::setFreesAttempted(int newVal) {
	freeThrows[getIndex()].setPointsAttempted(newVal);
}

void player::setIndex(int Index) {
	index = Index;
}

int player::getIndex() {
	return index;
};

int player::getThM() {
	return threePt[getIndex()].getPointsMade();
}

int player::getThA() {
	return threePt[getIndex()].getPointsAttempted();
}

int player::getTM() {
	return twoPt[getIndex()].getPointsMade();
}

int player::getTA() {
	return twoPt[getIndex()].getPointsAttempted();
}

int player::getFM() {
	return freeThrows[getIndex()].getPointsMade();
}

int player::getFA() {
	return freeThrows[getIndex()].getPointsAttempted();
}