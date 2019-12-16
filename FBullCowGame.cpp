#include "pch.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const Fstring HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring guess) const
{
	if (false) // if the guess isn't an isogram 
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (false) // if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::Ok; 
	}
}

//recieves a VALID guess, increments turn, and returns count 
FBullCowCount FBullCowGame::SubmitGuess(Fstring Guess)
{
	//increment the turn number

	MyCurrentTry++; 

	//setup a return variable

	FBullCowCount BullCowCount; 

	//loop through all the letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			//if they match
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				if (HWChar == GChar) { //if they are in the same place
					BullCowCount.Bulls++; // incriment bulls if they are in the same place
				}
				else {
				} BullCowCount.Cows++; // must be a cow
				
				
			}
		}
	}

	return BullCowCount;
}
