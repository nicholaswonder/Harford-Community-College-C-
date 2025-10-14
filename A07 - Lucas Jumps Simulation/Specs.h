#pragma once

class Sim {
private:
	short* row;
	short* answer;
	short input;
	
public:

	// Constructor
	Sim();

	// Initializer
	void buildBoards();

	// Getter
	short getInput();
	short getBoard(short); // Position to look at on game board
	short getAnswer(short); // Position of answer board to look at

	// Setter
	void setInput();
	void setBoard(short, short); // Position, Color

	// Print function
	void printBoard();

	// Move function
	void swapBoard(short); // Position of white

	// Check legality function
	bool checkMove();

	// Checks to see if any legal moves can still be made
	bool checkGimped();

	// Checks for user victory
	bool checkVictory();
};