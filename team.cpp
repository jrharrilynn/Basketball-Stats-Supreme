#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "Statistic.h";
#include "player.h";
#include <fstream>;
#include "team.h";
#include <sstream>;
#include<iomanip>


//initializes the team
team::team() 
{
	numPlayers = 0;
	numGames = 0;
}

//set and get methods
void team::setPlayers(int newNum) 
{
	numPlayers = newNum;
}

void team::setGames(int newNum)
{
	numGames = newNum;
	int x = getPlayers();
	
	//have to set the number of games for each player
	for (int i = 0; i < x; i++) {
		P[i].setGames(numGames);
	};
}

int team::getGames() 
{
	return numGames;
}

int team::getPlayers()
{
	return numPlayers;
}


//prints the team
void team::print() {
	int x = getPlayers();
	for (int i = 0; i < x; i++) {
		P[i].print();
		cout << endl;
	}
}

//adds a game to the players' list of games
void team::addGame() {
	int x = getGames();
	int y = getPlayers();
	int newThM;
	int newThA;
	int newTM;
	int newTA;
	int newFtM;
	int newFtA;

	//if too many games then it cant add any
	if (x >=15) {
		cout << "Too many games, can't add another" << endl;
	}

	//when it can add a game
	else {
		//increases amount of games by 1
		++x;
		setGames(x);
		//asks the users to enter the stats for i'th players new game
		for (int i = 0; i < y; i++) {
			cout << "Enter stats for " << P[i].getName() << "[" << P[i].getjerNum() << "]" << endl;
			cout << "3 Pointers (made attempted): ";
			cin >> newThM  >>newThA;
			cout << "2 pointers(made attempted): ";
			cin >> newTM >> newTA;
			cout << "Freethrows(made attempted): ";
			cin >> newFtM >> newFtA;
			//sets the statistics to the players new game
			P[i].setIndex(x-1);
			P[i].setThreesMade(newThM);
			P[i].setThreesAttempted(newThA);
			P[i].setTwosMade(newTM);
			P[i].setTwosAttempted(newTA);
			P[i].setFreesMade(newFtM);
			P[i].setFreesAttempted(newFtA);
			
		}
	}
}


//reads the given text file
void team::read() {
	string jerNum;
	string Name;
	ifstream fin;
	int numPlayers;
	int numGames;
	int threeM;
	int threeA;
	int twoM;
	int twoA;
	int freeM;
	int freeA;
	

	fin.open("bballin.txt");
	if (fin.fail())
	{
		cout << "FIle couldn't be found" << endl;
	}
	else
	{
		fin >> numPlayers;
		setPlayers(numPlayers);
		fin >> numGames;
		setGames(numGames);
		for (int i = 0; i < numPlayers; i++)
		{
			fin >> jerNum;
			P[i].setjerNum(jerNum);
			getline(fin, Name, '\n');
			P[i].setName(Name);
			for (int j = 0; j < numGames; j++)
			{
				P[i].setIndex(j);
				fin >> threeM;
				fin >> threeA;
				fin >> twoM;
				fin >> twoA;
				fin >> freeM;
				fin >> freeA;
				P[i].setThreesMade(threeM);
				P[i].setThreesAttempted(threeA);
				P[i].setTwosMade(twoM);
				P[i].setTwosAttempted(twoA);
				P[i].setFreesMade(freeM);
				P[i].setFreesAttempted(freeA);

			}
		}
	}

}

//give an index given a player number
int team::findPlayer() {
	string jerNum;
	//ask the user for a players jersey number
	cout << "Enter a players jersey Number" << endl;
	cin >> jerNum;

	//initiate linear search to find this jersey number
	int found = -1;
	for (int i = 0; i < getGames(); i++)
	{
		if (P[i].getjerNum() == jerNum)
			found = i;
	};

	//return the index if found or -1 if not
	return found;
}

//show user a player given a jersey number
void team::displayPlayer() 
{	
	//invoke find player to get an index
	int index=findPlayer();
	
	//use the value returned to tell the program which player to print
	if (index == -1) {
		cout<<"Player not found!"<<endl;
	}
	else {
		P[index].print();
	}
	
}

//removes a player based on jersey number
void team::removePlayer() {
	
	//invokes find player for index
	int index = findPlayer();
	player mem;
	//store the player with given jersey number 
	mem = P[index];
	//reduces number of players by 1
	numPlayers--;
		for (int i = index; i < numPlayers+1; i++)
		{
			P[i] = P[i + 1];
		}

		
	
		
	cout << mem.getName() << " Has been removed" << endl;
	
}

//performes a sort based on the players name
void team::sortByName() {
	for (int i = 0; i < numPlayers - 1; i++) {
		for (int j = i + 1; j < numPlayers; j++) {
			if (P[i].getName() > P[j].getName()) {
				Swap(i, j);
			};
		};
	}
	cout << "Players sorted by name\n";
};

//swaping function
void team::Swap(int& index1, int& index2) {
	player Temp = P[index1];
	P[index1] = P[index2];
	P[index2] = Temp;
}

//performs a sort based on the jersey number
void team::sortByJersey() {
	for (int i = 0; i < numPlayers - 1; i++) {
		for (int j = i + 1; j < numPlayers; j++) {
			if (P[i].getjerNum() > P[j].getjerNum()) {
				Swap(i, j);
			};
		};
	}
	cout << "Players sorted by Jersey Number\n";
};


//writes the output file
void team::write() {
	ofstream fout;
	fout.open("bballout.txt");
	if (fout.fail()) {
		cout << "unable to open file\n";
	}
	else {
		fout << numPlayers << " ";
		fout << numGames << "\n";
		for(int i=0;i<numPlayers;i++){
			
			fout << P[i].getjerNum();
			fout << P[i].getName() << "\n";
			for (int j = 0; j < numGames; j++) {
				P[i].setIndex(j);
				fout << P[i].getThM()<<" "<< P[i].getThA() <<" "<< P[i].getTM() <<" "<< P[i].getTA() <<" "<< P[i].getFM() <<" "<< P[i].getFA() << "\n";
			}
		}

	}

}

//prototype code to add player to test things
void team::addPlayer() {
	int y = getPlayers();
	std::string newPlayerName;
	std::string newPlayerNum;
	int gamesPlayed;
	int found;

	if (y >= 10) {
		cout << "Too many players, can't add another" << endl;
	}
	else {
		++y;
		setPlayers(y);
		for (int i = y-1; i < y; i++) {
			do {
				cout << "Enter new Jersey Number: " << endl;
				cin >> newPlayerNum;
				found = findPlayer();
			} while (found != -1);
			
			
			P[i].setjerNum(newPlayerNum);
			cout << "Enter new Players Name:";
			cin.get();
			getline(cin, newPlayerName);
			P[i].setName(newPlayerName);
			P[i].setGames(numGames);
			cout << newPlayerName << " Added!!\n";
		}
	}
}