#include "pch.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;
	
	const Fstring HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(Fstring)
{
	return false;
}

//recieves a VALID guess, increments turn, and returns count 
FBullCowCount FBullCowGame::SubmitGuess(Fstring)
{
	//increment the turn number

	MyCurrentTry++; 

	//setup a return variable

	FBullCowCount BullCowCount; 

	//loop through all the letters in the guess
		//compare letters against the hidden word
			//if they match
				// incriment bulls if they are in the same place
				//incriment cows if not


	return BullCowCount;
}
