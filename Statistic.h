//-------------------------------------
//                  class Statistic
//-------------------------------------
// Implements a the points made and attempted for a score type
//-------------------------------------

#pragma once
class Statistics
{
private:
	int pointsMade;
	int pointsAttempted;
public:
	Statistics();
	int getPointsMade();
	int getPointsAttempted();
	void setPointsMade(int newVal);
	void setPointsAttempted(int newVal);
	float calcPerc();
	void printStats();
};