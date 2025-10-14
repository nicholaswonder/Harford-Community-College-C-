// Made by Nick Wonder
#include <iostream>
#include <iomanip>
using namespace std;

void createTable(int**, int, int);

int main() {
	// Declaring variables
	int rows = 1;
	int columns = 1;
	int multiply = 0;
	int counterR = 1; // Counts rows for the table
	int counterC = 0; // Counts columns for the table
	int** pTable = NULL; // going to create the table after the user inputs the size

	// Reciving user input for table size
		// Input desired rows
	cout << "Input the number of rows desired [1 - 10]: ";
	cin >> rows;

		// Fail-check the input
	while (rows > 10 || rows < 1 || cin.fail() == true) {
		// Clear fail flag
		cin.clear();
		rewind(stdin);

		// Reprompt the user
		cout << "Invalid Input" << endl;
		cout << "Input the number of rows desired [1 - 10]: ";
		cin >> rows;
	}
	cout << endl;
	rows++;

		// Input desired columns
	cout << "Input the number of columns desired [1 - 10]: ";
	cin >> columns;
	

		// Fail-check the input again
	while (columns > 10 || columns < 1 || cin.fail() == true) {
		// Clear fail flag
		cin.clear();
		rewind(stdin);

		// Reprompt the user
		cout << "Invalid Input" << endl;
		cout << "Input the number of rows desired [1 - 10]: ";
		cin >> columns;
	}
	columns++;
	cout << endl << endl; // Making some space to make the output less cramped

	// Creating the array
	pTable = new(int* [rows]);
	for (int i = 0; i < rows; i++) {
		pTable[i] = new(int[columns]);
	}

	createTable(pTable, rows, columns);

	// Create the table
		// Top Row
	while (counterC < columns) {
		cout << setw(3) << right << counterC << "|";
		counterC++;
	}
	cout << endl;
	counterC = 0;

		// All the next rows
	while (counterR < rows) {
		// Inbetween lines
		while (counterC < columns) {
			cout << "---+";
			counterC++;
		}
		cout << endl;
		counterC = 1;

		// Information row
		cout << setw(3) << right << counterR << "|";
		while (counterC < columns) {
			cout << setw(3) << right << pTable[counterR][counterC] << "|";
			counterC++;
		}
		cout << endl;
		counterC = 0;
		counterR++;
	}

	cout << endl << endl;

	return 0;
}

void createTable(int** pTable, int rows, int columns) {
	int counterC = 0; // Counts columns for the loop
	int counterR = 0; // Counts rows for the loop

	while (counterR < rows) {
		while (counterC < columns) {
			pTable[counterR][counterC] = counterR * counterC;
			counterC++;
		}
		counterC = 0;
		counterR++;
	}
}