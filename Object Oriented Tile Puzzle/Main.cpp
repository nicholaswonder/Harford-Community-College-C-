// Main

#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include "Tile Specs.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define QUIT  20

using namespace std;

int main() {
	short input = 0;
	short columns = 0;
	short rows = 0;
	bool legal = false;
	bool victory = false;

	// Summoning RNJesus
	srand((unsigned int)time(NULL));

	// Prompting user to input desired table sizes
	cout << "Enter how many columns the game should have (3 - 10): ";
	do {
		cin >> columns;
		if (cin.fail() == true || columns < 3 || columns > 10) {
			cin.clear();
			rewind(stdin);
			cout << "Invalid input - try again: ";
		}
	} while (columns < 3 || columns > 10);

	cout << "Enter how many rows the game should have (3 - 10): ";
	do {
		cin >> rows;
		if (cin.fail() == true || rows < 3 || rows > 10) {
			cin.clear();
			rewind(stdin);
			cout << "Invalid input - try again: ";
		}
	} while (columns < 3 || columns > 10);
	cout << "Loading...";

	// Run the parameterized constructor
	Tile game(columns, rows);

	game.printBoard();
	getch();
	game.startGameLoop();
	game.scrambleBoard();


	// Game loop
	do {
		system("cls");
		game.printBoard();
		do {
			input = game.getInput();

			// Quit condition
			if (input == QUIT) {
				break;
			}

			legal = game.slideTile(input); // Checks if move is successful
		} while (legal == false);

		// Quit Condition
		if (input == QUIT) {
			break;
		}

		// To continue the game as normal
		victory = game.isBoardSolved();
	} while (victory == false);

	system("cls");

	if (input == QUIT) {
		cout << "Thanks for playing!" << endl << endl;
		return 0;
	}
	else if (victory == true) {
		cout << "YOU WIN!" << endl << endl;
		return 0;
	}
}