#pragma once
#include <string> 


class FBullCowGame {
public:
	
	FBullCowGame(); //constructor

	int GetMaxTries() const; 
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //to do make a more richer value
	bool CheckGuessValidity(std::string); //to do make a more richer value

private:
	// see constrtuctor for initalisation
	int MyCurrentTry;
	int MyMaxTries;
};
