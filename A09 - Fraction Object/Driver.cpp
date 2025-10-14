#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Specification.h"
using namespace std;

int main() {
	// Instantiate the Fraction.
	Fraction frac_1(3, 9);
	Fraction frac_2(11, 19);
	Fraction sum;
	Fraction difference;
	Fraction product;
	Fraction quotient;

	sum = frac_1 + frac_2;
	cout << sum;

	cout << endl << endl;

	difference = frac_2 - frac_1;
	cout << difference;

	cout << endl << endl;

	product = frac_1 * frac_2;
	cout << product;

	cout << endl << endl;
	quotient = frac_2 / frac_1;
	cout << quotient;

	// It's Over!
	_getch();
	return 0;
}