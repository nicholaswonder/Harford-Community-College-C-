#include "Specs.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

#pragma warning(disable:4996)

// Defining the dots as their color values in the console output
#define INVALID  -1
#define BLUE      9
#define WHITE     7
#define RED      12

using namespace std;

Sim::Sim() {
	// Making arrays, wish they didnt have to be pointers, but whatever
	row = new(short[8]);
	answer = new(short[8]);
	input = -1;
}

void Sim::buildBoards() {
	// Initializing arrays, defining the array values as color values helps with the printing function
	// Note - I initialize the first and last values as "INVALID" to help prevent errors
	row[0] = INVALID;
	for (short i = 1; i < 4; i++) {
		row[i] = BLUE;
	}
	row[4] = WHITE;
	for (short i = 5; i < 8; i++) {
		row[i] = RED;
	}
	row[8] = INVALID;

	// Initializing the answer array as the solution
	answer[0] = INVALID;
	for (short i = 1; i < 4; i++) {
		answer[i] = RED;
	}
	answer[4] = WHITE;
	for (short i = 5; i < 8; i++) {
		answer[i] = BLUE;
	}
	answer[8] = INVALID;
}

// Data encapulation for the main array
short Sim::getBoard(short position) {
	return row[position];
}

short Sim::getAnswer(short position) {
	return answer[position];
}

void Sim::setBoard(short position, short color) {
	row[position] = color;
}

void Sim::printBoard() {
	// Uses the previously mentioned color tactic to create colors on the console output
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i < 8; i++) {
		SetConsoleTextAttribute(hConsole, getBoard(i));
		cout << " O ";
	}
	SetConsoleTextAttribute(hConsole, WHITE);
	// To help visulize the players choice of input
	cout << endl << " 1  2  3  4  5  6  7 " << endl;
}

// Gets user input
void Sim::setInput() {
	do {
		/* I use getch because it helps speed up the process
		However, this is best used for characters and returns ascii values for numbers
		so, I subtract 48 since 0's ascii value is 48 and so on */
		input = getch();
		input = input - 48;
		if (cin.fail() == true || input < 1 || input > 7) {
			cin.clear();
			rewind(stdin);
			cout << "Invalid choice - Try again" << endl;
		}
	} while (cin.fail() == true || input < 1 || input > 7);
}

// Data encapsulation
short Sim::getInput() {
	return input;
}

// Simple value swap function
void Sim::swapBoard(short whiteSpace) {
	short storage = getBoard(getInput());
	setBoard(getInput(), WHITE);
	setBoard(whiteSpace, storage);
}

// This function checks whether a move is legal, and if so, swaps the tiles
bool Sim::checkMove() {
	short color = getBoard(getInput());

	switch (color) {
	case BLUE:
		if (getBoard(getInput() + 1) == WHITE) {
			swapBoard(getInput() + 1);
			return true;
			break;
		}
		else if (getBoard(getInput() + 2) == WHITE) {
			swapBoard(getInput() + 2);
			return true;
			break;
		}
		else{
			cout << "Illegal Move" << endl;
			return false;
			break;
		}

	case RED:
		if (getBoard(getInput() - 1) == WHITE) {
			swapBoard(getInput() - 1);
			return true;
			break;
		}
		else if (getBoard(getInput() - 2) == WHITE) {
			swapBoard(getInput() - 2);
			return true;
			break;
		}
		else {
			cout << "Illegal Move" << endl;
			return false;
			break;
		}

	case WHITE:
		cout << "Thats the white tile!" << endl;
		return false;
		break;

	default:
		cout << "Something horrible has happened - checkMove" << endl;
	}
}

bool Sim::checkGimped() {
	/* Instead of checking every tile for a legal move, I am going to find the white dot, and look at the two tiles
	   to its left and right for blue and red tiles respectivly. If there arent any tiles in that zone that match
	   the criteria, logically the game is either gimped or won. */

	// Finding the white dot
	short whiteDot = 0;
	for (short i = 0; i < 8; i++) {
		if (getBoard(i) == WHITE) {
			whiteDot = i;
			break;
		}
	}

	// If both of these remain false, board is gimped
	bool left = false;
	bool right = false;

	// Checking left of white dot for a blue dot for play
	switch (getBoard(whiteDot - 1)) {
	case INVALID:
		left = false;
		break;
	case BLUE:
		left = true;
		break;
	case RED:
		/* Unfortunately, the best way I can think of to check these values properly without chance of screwing up
		*  is to nest another switch inside. I could use loops, but the "break" command only breaks out of the switch statement
		*  so, to make it easier to read and write, without having to worry about more variables and going out of bounds
		*  I am just going to nest. "He He He Haw" - Clash Royale Man */
		switch (getBoard(whiteDot - 2)) {
		case INVALID:
			left = false;
			break;
		case BLUE:
			left = true;
			break;
		case RED:
			left = false;
			break;
		default:
			cout << "Something horrible has happened - checkGimped left : Nested" << endl;
			left = false;
		}
		break;
		// End nesting
	default:
		cout << "Something horrible has happened - checkGimped left" << endl;
		left = false;
		break;
	}

	// Checking right side for a playable red dot
	switch (getBoard(whiteDot + 1)) {
	case INVALID:
		right = false;
		break;
	case RED:
		right = true;
		break;
	case BLUE:
		// Begin nesting
		switch (getBoard(whiteDot + 2)) {
		case INVALID:
			right = false;
			break;
		case BLUE:
			right = false;
			break;
		case RED:
			right = true;
			break;
		default:
			cout << "Something horrible has happened - checkGimped right : Nested" << endl;
			right = false;
		}
		break;
		// End nesting
	default:
		cout << "Something horrible has happened - checkGimped right" << endl;
		right = false;
		break;
	}

	if (left == false && right == false) { // If no playable dots, board is gimped
		return true;
	}
	else {
		return false;
	}
}

bool Sim::checkVictory() {

	// Goes through each valid spot on the board to check whether
	// the game has been won
	for (short i = 1; i < 8; i++) {
		if (getBoard(i) != getAnswer(i)) {
			return false; // If it finds one wrong value, game is not won
		}
	}

	// If the loop manages to complete, then there are no wrong values, and the game is won.
	return true;
}