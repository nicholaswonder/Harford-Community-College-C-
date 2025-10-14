#include <iostream>
using namespace std;

// CONSTANTS
const int STRING_SIZE = 100;

// PROTOTYPES
int ReverseStringRecursive(char*);

// MAIN
int main() {
	// create a string
	char someString[STRING_SIZE] = "abcdefghijklmnopqrstuvwxyz";

	// display the string before being reversed
	cout << "The string contains: " << endl;
	cout << someString << endl << endl;

	// make the call to the recursive function
	cout << "CALL THE REVERSING FUNCTION" << endl << endl;
	ReverseStringRecursive(someString);

	// display the string after being reversed
	cout << "The string contains: " << endl;
	cout << someString << endl;

	// exit program
	return 0;
}

// FUNCTION IMPLEMENTATIONS
int ReverseStringRecursive(char* reverseMe) {
	char storage;
	static int memLocation; // defaults to 0, I dont wanna reinitialize it and screw up the count
	
	if (reverseMe[memLocation] != '\0'){
		storage = reverseMe[memLocation]; // Recursive storage, store each character one by one
		memLocation++; // Move the memory location forward by one, int is static so it stays between loops
		memLocation = ReverseStringRecursive(reverseMe); // Next recursion loop
		reverseMe[memLocation] = storage; // This works since the code begins to work backwards after recursion ends.
		return (memLocation + 1); // Increments the memory location for the next loop
	}
	else {
		return 0; // Sets the location back to the beginning to start the actual work
	}  
}