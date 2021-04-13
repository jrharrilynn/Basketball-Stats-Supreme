#include "Statistic.h"
#include <iostream>
#include <iomanip>
using namespace std;


//set and get methods
int Statistics::getPointsMade() {
	return pointsMade;
};

int Statistics::getPointsAttempted() {
	return pointsAttempted;
};

void Statistics::setPointsMade(int newVal) {
	pointsMade = newVal;
}

void Statistics::setPointsAttempted(int newVal) {
	pointsAttempted = newVal;
}

//initialize the statistics
Statistics::Statistics() {
	pointsAttempted = 0;
	pointsMade = 0;
}

//calculates the percentage of points made to attempted
float Statistics::calcPerc() {
	int x=getPointsAttempted();
	int y=getPointsMade();
	float perc;
	if (x <= 0) {
		perc = 0.0;
	}
	else
		perc = (100 * y / x);
	return perc;
}

//prints the statistic
void Statistics::printStats() {
	int x=getPointsAttempted();
	int y = getPointsMade();
	float z = calcPerc();

	cout << setw(2) << y << "/" << setw(2) << x << " (" << setw(3) << setprecision(0) << fixed << z << ")";
}