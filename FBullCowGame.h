#pragma once
#include <string> 

using int32 = int;
using Fstring = std::string; 

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase, 
};

class FBullCowGame {
public:
	
	FBullCowGame(); //constructor

	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(Fstring) const;

	void Reset(); //TODO make a more richer value
	FBullCowCount SubmitValidGuess(Fstring);

private:
	// see constrtuctor for initalisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(Fstring) const; 
	bool IsLowercase(Fstring) const;
};
