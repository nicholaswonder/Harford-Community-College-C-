// Implementation

#pragma warning(disable:4996)

#include "Tile Specs.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

// Define directional codes
#define SLIDE_UP     1
#define SLIDE_DOWN   2
#define SLIDE_LEFT   3
#define SLIDE_RIGHT  4
#define QUIT         20

// Define the pivot point for the sake of readablility
#define PIVOT        0

// Define colors
#define WHITE        7
#define RED          12
#define GREEN        10

using namespace std;

// Constructor
Tile::Tile() {
	// Adjustible size variables
	columns = 3;
	rows = 3;

	// Creating Game Table - Initially a 3 x 3
	pGameTable = new(int* [rows]);
	for (int i = 0; i < rows; i++) {
		pGameTable[i] = new(int[columns]);
	}

	// Creating Answer Table
	pAnswerTable = new(int* [rows]);
	for (int i = 0; i < rows; i++) {
		pAnswerTable[i] = new(int[columns]);
	}

	initializeTables();

	// Ill explain this in the startGameLoop function
	gameLoop = false;
}

// Parameterized constructor
Tile::Tile(int numCols, int numRows) {
	columns = numCols;
	rows = numRows;

	// Creating Game Table - Now custom for the user
	pGameTable = new(int* [rows]);
	for (int i = 0; i < rows; i++) {
		pGameTable[i] = new(int[columns]);
	}

	// Creating Answer Table
	pAnswerTable = new(int* [rows]);
	for (int i = 0; i < rows; i++) {
		pAnswerTable[i] = new(int[columns]);
	}

	initializeTables();

	gameLoop = false;

	system("cls");
}

// Setter
void Tile::initializeTables() {
	// Initializing the tables
	int numcount = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			pGameTable[i][j] = numcount;
			numcount++;
		}
	}
	pGameTable[rows - 1][columns - 1] = PIVOT;

	numcount = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			pAnswerTable[i][j] = numcount;
			numcount++;
		}
	}
	pAnswerTable[rows - 1][columns - 1] = PIVOT;
}

void Tile::startGameLoop() {
	// This just serves as a really basic variable that determines whether or not the board has
	// been scrambled yet, therefor dictating whether the printBoard function will show the controls
	// or prompt the user to press a key to start the scramble
	gameLoop = true;
}

// Getters
int Tile::getInput() {
	char input = 'z';
	
	do {
		input = getch();
		// Basic input fail-check
		if (cin.fail() == true || input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'p') {
			cin.clear();
			rewind(stdin);
			cout << "Invalid input - Try Again!" << endl;
		}
	} while (input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'p');

	// Determines what value to return
	switch (input) {
	case 'w':
		return SLIDE_UP;
		break;
	case 'a':
		return SLIDE_LEFT;
		break;
	case 's':
		return SLIDE_DOWN;
		break;
	case 'd':
		return SLIDE_RIGHT;
		break;
	case 'p':
		return QUIT;
		break;
	default:
		cout << "something horrible has happened - GET_INPUT" << endl;
		return QUIT;
	}
}

// All the other functions
void Tile::printBoard() {
	// To add color
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = WHITE;

	// Goes one by one to display each value
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (pGameTable[i][j] == PIVOT) {
				color = WHITE;
				SetConsoleTextAttribute(hConsole, color);
				cout << "  *";
			}
			else{
				if (pGameTable[i][j] == pAnswerTable[i][j]) {
					color = GREEN;
				}
				else {
					color = RED;
				}
				SetConsoleTextAttribute(hConsole, color);
				cout << setw(3) << right << pGameTable[i][j];
			}
		}
		cout << endl;
	}
	// Create some room
	cout << endl << endl;

	// Prints the controls for the user
	color = WHITE;
	SetConsoleTextAttribute(hConsole, color);

	// Gameloop purpose explained in gameLoop setter
	if (gameLoop == false) {
		cout << "Press any key to scramble" << endl;
	}
	else {
		cout << "Controls:" << endl;
		cout << "W -> Up | A -> Left | S -> Down | D -> Right | P -> Quit the game" << endl;
	}
}

bool Tile::slideTile(int input) {
	int storage = 0;
	int desiredRow = 0;
	int desiredCol = 0;
	int currentCol = 0;
	int currentRow = 0;
	bool legal = false;
	
	// Dynamically find the position of the pivot point
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (pGameTable[i][j] == PIVOT) {
				currentCol = i;
				currentRow = j;
			}
		}
	}

	if (legalMove(currentCol, currentRow, input) == true) {
		// If the move is legal, find the coordinate of desired pivot location
		switch (input) {
		case SLIDE_UP:
			desiredRow = currentRow;
			desiredCol = currentCol - 1;
			break;
		case SLIDE_DOWN:
			desiredRow = currentRow;
			desiredCol = currentCol + 1;
			break;
		case SLIDE_LEFT:
			desiredCol = currentCol;
			desiredRow = currentRow - 1;
			break;
		case SLIDE_RIGHT:
			desiredCol = currentCol;
			desiredRow = currentRow + 1;
			break;
		}

		// Swaps the values of the current and new positions
		storage = pGameTable[desiredCol][desiredRow];
		pGameTable[desiredCol][desiredRow] = PIVOT;
		pGameTable[currentCol][currentRow] = storage;
		return true;
	}
	else {
		// Make the user put in another move
		cout << "Illegal Move - Try again" << endl;
		return false;
	}
}

bool Tile::legalMove(int x, int y, int input) {
	int desiredX = 0;
	int desiredY = 0;

	// Uses math to find where the user wants to move the pivot point and sees if thats within the board bounds
	switch (input) {
	case SLIDE_UP:
		desiredX = x - 1;
		if (desiredX < 0) {
			return false;
		}
		else {
			return true;
		}
		break;
	case SLIDE_DOWN:
		desiredX = x + 1;
		if (desiredX > (rows - 1)) {
			return false;
		}
		else {
			return true;
		}
		break;
	case SLIDE_LEFT:
		desiredY = y - 1;
		if (desiredY < 0) {
			return false;
		}
		else {
			return true;
		}
		break;
	case SLIDE_RIGHT:
		desiredY = y + 1;
		if (desiredY > (columns - 1)) {
			return false;
		}
		else {
			return true;
		}
		break;
	default:
		cout << "something horrible has happened - LEGAL_MOVE" << endl;
		return false;
	}
}

// Board Scrambler
void Tile::scrambleBoard() {
	int randomMove = 0;
	int currentRow = 0;
	int currentCol = 0;
	bool legal = false;
	int counter = 0;

	while (counter < 500) {
		// Finds the pivot point
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (pGameTable[i][j] == PIVOT) {
					currentCol = i;
					currentRow = j;
				}
			}
		}

		// Generates a random direction to move
		randomMove = (rand() % 4) + 1;

		// Check if generated move is legal
		if (legalMove(currentCol, currentRow, randomMove) == true) {
			slideTile(randomMove);
			counter++;
		}
		// If generated move isnt legal, the counter doesnt update so the code generates another
	}
}

bool Tile::isBoardSolved() {
	int correct = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (pGameTable[i][j] == pAnswerTable[i][j]) {
				correct++;
			}
		}
	}
	cout << correct << endl;
	if (correct == (rows * columns)) {
		return true;
	}
	else {
		return false;
	}
}

Tile::~Tile() {
	for (int i = 0; i < rows; i++) {
		delete pGameTable[i];
	}
	delete pGameTable;

	for (int i = 0; i < rows; i++) {
		delete pAnswerTable[i];
	}
	delete pAnswerTable;

	pGameTable = NULL;
	pAnswerTable = NULL;
}