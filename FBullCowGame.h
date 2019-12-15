#pragma once
#include <string> 

using int32 = int;
using Fstring = std::string; 

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	
	FBullCowGame(); //constructor

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //to do make a more richer value
	bool CheckGuessValidity(Fstring); //to do make a more richer value
	
	//counts bulls and cows and increases try number, assuming valid guess
	FBullCowCount SubmitGuess(Fstring); 

private:
	// see constrtuctor for initalisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
};
