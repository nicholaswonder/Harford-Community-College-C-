// Starter code provided by Mark Densler
// Functionality made by Nick Wonder
#pragma warning(disable:4996)

#include <iostream>				// for general IO
#include <iomanip>				// for setw()
using namespace std;

#include <string.h>				// for strcpy()
#include <conio.h>				// for getche()

#include <windows.h>			// for COLOR!

#include <time.h>               // To help scramble the board

#define NUM_ROWS		3		// should not be changed for this solution
#define NUM_COLS		3		// should not be changed for this soultion

#define PIVOT -1				// used to mark the pivot spot (blank area) on the puzzle
#define PIVOT_SYMBOL	"*"		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10


// PROTOTYPES
void InitializeBoard(int**); // Adds the values to the arrays
void PrintBoard(int**, int**); // Displays the board on the screen
int recieveUserInput(); // Sees the button the user presses
bool legalMove(int, int, int); // Checks to see if a move is legal from the pivots current location
bool slideTile(int**, int); // Moves the tiles
void scrambleBoard(int**);		// depends upon slideTile()
bool isBoardSolved(int**, int**);		// indicates if the board is in the SOLVED state
bool isTileCorrect(int**, int**, int, int); // indicates if a tile is in the SOLVED state (useful for the color)

// DEVELOPMENT EXTRAS
//void printTheRainbow();								// A little reminder on how to do color with the Windows API.


int main() {
	// Variables
	int userInput = 0;
	bool victory = false; // Used to detect when the loop and the game should end
	int** pGameTable = NULL;
	int** pSolvedTable = NULL;

	// To help with output color
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	srand((unsigned int)time(NULL)); // Seed the rng to system clock for scrambling

	// Create the pointer arrays
	pGameTable = new(int* [NUM_ROWS]);
	for (int i = 0; i < NUM_COLS; i++) {
		pGameTable[i] = new(int[NUM_COLS]);
	}

	pSolvedTable = new(int* [NUM_ROWS]);
	for (int i = 0; i < NUM_COLS; i++) {
		pSolvedTable[i] = new(int[NUM_COLS]);
	}
	
	InitializeBoard(pGameTable); // I make sure to initialize it to be correct before a scrambling
	InitializeBoard(pSolvedTable);

	PrintBoard(pGameTable, pSolvedTable);
	cout << endl;
	cout << "Press any key to scramble" << endl;
	_getch();
	scrambleBoard(pGameTable);
	
	while (victory == false) {
		system("cls");
		PrintBoard(pGameTable, pSolvedTable);
		cout << endl;
		SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
		cout << "Controls:" << endl;
		cout << "W -> Up | A -> Left | S -> Down | D -> Right" << endl;
		slideTile(pGameTable, recieveUserInput());
		victory = isBoardSolved(pGameTable, pSolvedTable);
	}
	system("cls");
	cout << "YOU WIN!" << endl;

	// Exit
	_getch();
	return 0;
}

void InitializeBoard(int** pTable) {
	int numCount = 1;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			pTable[i][j] = numCount; 
			numCount++;
		}
	}
	pTable[2][2] = 0;
}

void PrintBoard(int** pGameTable, int** pSolvedTable) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 0;

	// Just goes one by one, displaying each value in the grid pattern
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			// Handling the colors of the text might handle best here
			if (pGameTable[i][j] == 0) {
				color = COLOR_DEFAULT;
				SetConsoleTextAttribute(hConsole, color);
				cout << "  *";
			}
			else {
				// Setting the color of the tiles
				if (isTileCorrect(pGameTable, pSolvedTable, i, j) == true) {
					color = COLOR_GREEN;
					SetConsoleTextAttribute(hConsole, color);
				}
				else {
					color = COLOR_RED;
					SetConsoleTextAttribute(hConsole, color);
				}
				cout << setw(3) << right << pGameTable[i][j];
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, color);
	color = COLOR_DEFAULT;
}

int recieveUserInput() {
	char input = 'e';
	
	do{
		input = getch();
		// Basic input fail-check
		if (cin.fail() == true || input != 'w' && input != 'a' && input != 's' && input != 'd') {
			cin.clear();
			cout << "Invalid input - Try Again!" << endl;
		}
	} while (input != 'w' && input != 'a' && input != 's' && input != 'd');
	
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
	}
}

bool legalMove(int x, int y, int input) {
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
		if (desiredX > 2) {
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
		if (desiredY > 2) {
			return false;
		}
		else {
			return true;
		}
		break;
	}
}

bool slideTile(int** pGameTable, int input) {
	int storage = 0;
	int desiredCol = 0;
	int desiredRow = 0;
	int currentCol = 0;
	int currentRow = 0;
	bool legal = false;

	// Dynamically finds the position of the pivot point
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (pGameTable[i][j] == 0) {
				currentCol = i;
				currentRow = j;
			}
		}
	}

	legal = legalMove(currentCol, currentRow, input);

	// If the move is legal, find the new coordinates of the pivot
	if (legal == true) {
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
		pGameTable[desiredCol][desiredRow] = 0;
		pGameTable[currentCol][currentRow] = storage;
		return true;
	}
	else {
		// Makes the user retry their move if it's illegal
		cout << "Illegal Move - Press any key to retry input" << endl;
		_getch();
		return false;
	}
}

void scrambleBoard(int** pGameTable) {
	int randomMove = 0;
	int currentRow = 0;
	int currentCol = 0;
	bool legal = false;
	int counter = 0;

	while (counter < 1000) {
		// Find the pivot point
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLS; j++) {
				if (pGameTable[i][j] == 0) {
					currentCol = i;
					currentRow = j;
				}
			}
		}

		randomMove = (rand() % 4) + 1; // Generates the move

		// Check if random move is legal
		legal = legalMove(currentCol, currentRow, randomMove);

		// If so, move the pivot
		if (legal == true) {
			slideTile(pGameTable, randomMove);
			counter++;
		}
		// If move is not legal, the counter is not updated
		// and another move is generated
	}
}

bool isTileCorrect(int** pGameTable, int** pSolvedTable, int col, int row) {
	if (pGameTable[col][row] == pSolvedTable[col][row]) {
		return true;
	}
	else {
		return false;
	}
}

bool isBoardSolved(int** pGameTable, int** pSolvedTable) {
	int correct = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (pGameTable[i][j] == pSolvedTable[i][j]) {
				correct++;
			}
		}
	}
	cout << correct << endl;
	if (correct == 9) {
		return true;
	}
	else {
		return false;
	}
}
