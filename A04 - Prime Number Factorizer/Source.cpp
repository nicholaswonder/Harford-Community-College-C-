// Made by Nick Wonder

#include <iostream>
using namespace std;

bool primeTest(int);
int findFactors(int);

int main() {
	/*
	* Plan for development
	* 1) Intake the desired test number (i)
	* 2) Divide by every number within the range of 2 to (i/2)
	* 3) If no numbers return whole, number is prime, program ends
	* 4) If numbers do return whole, display factor and repeat step 2 on new number
	*	 Repeat until both the factor and new number are the same, where both are factors
	*	 Or until the last number is prime
	*/

	// Variables
	int input = 0; // using a double that way its much easier to tell whether something is truely divisible
	int storage = 0; // used to store the larger factor in the function for further factorization

	// User Input
	cout << "Input the integer you would like to test: ";
	cin >> input;
	while (cin.fail() == true || input <= 0) {
		cin.clear();
		rewind(stdin);
		cout << "Invalid input - Enter a whole number: ";
		cin >> input;
	}

	if (primeTest(input) == false) { // If it isnt a prime number, begin finding factors
		// Find the factors one by one
		storage = findFactors(input);
		while (storage != -1) {
			storage = findFactors(storage);
		}
	}
	else { // If it is, just say so...
		cout << input << " is a prime number" << endl;
	}

	return 0;
}

// Tests to see if the input is prime
bool primeTest(int input) {
	if (input == 2) {
		return true;
	}
	else if (input == 1) {
		return false;
	}
	else {
		for (int i = 2; i < (input / 2); i++) { 
			if ((int)input % i == 0) {
				return false; // Proves to not be a prime
			}
		}
		return true; // Only if the for loops completes without already returning a value
	}
}

// Goes number by number to find the next factors
int findFactors(int number) {
	if (number % 2 == 0) { // Checks to see if number is divisible by 2
		cout << "2 is a prime factor" << endl;
		return (number / 2);
	}
	else {
		for (int i = 3; i < (number / 2); i = i + 2) { // If number isn't divisible by 2, try dividing by 3, 5, 7, and so on...
			if ((int)number % i == 0) {
				cout << i << " is a prime factor" << endl; // until either a factor is found
				return (number / i);
			}
		}
		cout << number << " is a prime factor" << endl; // or until the test number is proven to be prime
		return -1;
	}
}