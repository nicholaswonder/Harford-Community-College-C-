#include "Specs.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	Sim game;
	bool valid = false; // To help with the input loop
	bool victory = false; // To help with the game loop
	bool gimped = false;
	game.buildBoards(); // Initializes the boards
	
	do {
		game.printBoard(); // Prints board
		cout << endl << "Select which tile to move" << endl;
		do {
			game.setInput(); // Gets user input
			valid = game.checkMove(); // Checks if move is legal, swaps tiles
		} while (valid == false);
		
		victory = game.checkVictory();
		gimped = game.checkGimped();
		system("cls");
		
	} while (victory == false && gimped == false);

	if (victory == true) {
		cout << "YOU WIN" << endl << endl;
	}
	else if (gimped == true) {
		cout << "YOU GOT GIMPED" << endl << endl;
	}
	
	return 0;
}