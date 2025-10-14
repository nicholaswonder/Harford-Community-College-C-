#include "Specifications.h"
#include <iostream>

using namespace std;

int main() {
	Vector vector(5, 3);
	Vector vector2(10, 7);
	Vector vector3;
	
	// Assignment
	vector3 = vector;
	cout << "ASSIGNMENT" << endl;
	cout << vector3 << endl;

	// Addition
	Vector vector4 = vector + vector2;
	cout << "ADDITION" << endl;
	cout << vector4 << endl;

	// Subraction
	Vector vector5 = vector2 - vector;
	cout << "SUBRACTION" << endl;
	cout << vector5 << endl;


	return 0;
}