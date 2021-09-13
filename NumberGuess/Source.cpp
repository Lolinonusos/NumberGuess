#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

int theNumber{};	 // This is the number you are trying to find
int guess{};		 // This is your guess
int choosediff{};	 // This is used to decide your difficulty
int difficulty{};	 // Decides the range of numbers later
int tries{};		 // Will count how many times you tried to guess the correct number
int highScore = 200; // Set yo a hopefully unreasonably high number
char yOrN{};		 // A yes or no question that comes at the end of a round ()

int main() {
	std::cout << "Select difficulty:\n" << "1. Easy\n" << "2. Medium\n" << "3. Hard\n" << "4. Nightmare" << std::endl;
	
	do { // Decide difficulty; range of numbers you guess between
		std::cin >> choosediff;

		switch (choosediff) {
		case 1:
			difficulty = 10;
			break;
		case 2:
			difficulty = 50;
			break;
		case 3:
			difficulty = 100;
			break;
		case 4:
			difficulty = 200;
		default:
			std::cout << "Please use the numbers 1, 2 or 3 to choose your difficulty." << std::endl;
			break;
		}
	} while (choosediff <= 0 || choosediff >= 5);
	
	do // The Game
	{
		tries = 0; // Resets tries to 0 to make highscores possible
	
	system("cls");
	std::srand(time(0)); // Our seed
	theNumber = rand() % difficulty + 1;
	//std::cout << theNumber << std::endl;      // Just for testing purposes, enable the code for secret hacker mode
	
	//std::cout << "Currently for testing: Enter a number: ";
	//std::cin >>  theNumber;
	//system("cls"); // Hide the number from your friend

	std::cout << "Guess a number between 1 and " << difficulty << "! " << std::endl;
	
	do { // Loops until you guess correctly
		std::cin >> guess; tries++; // Count amount of guesses
	
	if (guess == theNumber) {		// Wins the game
		system("cls");
		std::cout << "Correct! The number was " << theNumber << std::endl;
	}
	else if (guess < theNumber) {
		std::cout << "To low, guess again: ";
	}
	else if (guess > theNumber) {
		std::cout << "To high, guess again: ";
	}
	} while (guess != theNumber);

	// This happens when the game is won
	std::cout << "You guessed a total of " << tries << " times.\n" << std::endl;
	if (tries < highScore) {
		highScore = tries;
		std::cout << "You got a new high score!!!" << std::endl;
	}
	std::cout << "HighScore: " << highScore << std::endl << std::endl;
	std::cout << "If you wish to try again, input 'y' or 'Y'" << std::endl;
	std::cin >> yOrN;
	

	} while (yOrN == 'y' || yOrN == 'Y'); // Loops the game if 'y' is pressed

	return 0;
}