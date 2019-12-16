#include "pch.h"
#include "FBullCowGame.h"
#include <map> 
// to make syntax unreal friendly
#define TMap std::map 

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 15}, {7, 20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const Fstring HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false; 
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring guess) const
{
	if (!IsIsogram(guess)) // if the guess isn't an isogram 
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (!IsLowercase(guess)) // if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase; //TODO write function
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
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)
{
	MyCurrentTry++; 
	FBullCowCount BullCowCount; 
	int32 WordLength = MyHiddenWord.length(); //assume the same length as guess

	//loop through all the letters in the hidden word
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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
	if (BullCowCount.Bulls == WordLength) 
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(Fstring Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) 	// for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) {// if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;// add the letter to the map
		}
	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(Fstring Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))// if not a lowercase letter
		{
			return false;
		}
	}
	return true;
}
