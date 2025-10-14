// Header
#pragma once

class Tile {
private:
	
	int** pGameTable;
	int** pAnswerTable;
	bool gameLoop;
	// For the adjustible game board size
	int columns;
	int rows;

public:
	// Constructor
	Tile();
		// Parameterized Constructor
	Tile(int, int); // # of columns, # of rows

	// Getting
	int getInput();

	// Setting
	void initializeTables();
	void startGameLoop();

	// All the other functions
		// Prints the boards
	void printBoard();

		// Swaps the tile
	bool slideTile(int); // User input
		
		// Checks if the given move is legal
	bool legalMove(int, int, int); // Current x, Current y, User input

		// Checks if the puzzle has been solved
	bool isBoardSolved();

		// Scrambles the board
	void scrambleBoard();

		// Destructor
	~Tile();
};