#pragma once
#include <string> 

class FBullCowGame {
public:
	void Reset(); //to do make a more richer value
	int GetMaxTries(); 
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); //to do make a more richer value

private:
	int MyCurrentTry;
	int MyMaxTries;
};
