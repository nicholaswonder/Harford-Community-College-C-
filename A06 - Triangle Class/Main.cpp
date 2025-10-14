// main
#include "Triangle Spec.h"
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

void displayInterface(Triangle);

int main() {
	Triangle triangle;
	float newValue = 0;
	char loop = 'q';
	bool accepted = false;

	do {
		system("cls");
		displayInterface(triangle);
		do {
			cout << "Change values? (y/n): ";
			cin >> loop;
			if ((loop != 'y' && loop != 'n') || cin.fail() == true) {
				cin.clear();
				cout << "Invalid Input" << endl;
			}
		} while (loop != 'y' && loop != 'n');
		switch (loop) {
		case 'y':
			do {
				cout << "New adjacent value: ";
				cin >> newValue;
				accepted = triangle.setAdjacent(newValue);
			} while (accepted == false);

			do {
				cout << "New opposite value: ";
				cin >> newValue;
				accepted = triangle.setOpposite(newValue);
			} while (accepted == false);
			break;
		case 'n':
			cout << endl << endl;
			return 0;
		}
	} while (loop == 'y');

}

void displayInterface(Triangle triangle) {
	cout << endl << endl;
	// Make the interface look good
	cout << "       *" << endl;
	cout << "       **" << endl;
	cout << "       * *" << endl;
	cout << "       *  *" << endl;
	cout << setw(6) << triangle.getOpposite() << " *   *  " << triangle.getHypotonuse() << endl; // sad I cant line it up to look nice but what can ya do
	cout << "       *    *" << endl;
	cout << "       *     *" << endl;
	cout << "       ********" << endl;
	cout << "       " << setw(6) << triangle.getAdjacent() << endl;
	cout << endl;
	cout << "The area is: " << triangle.getArea() << endl;
	cout << "The perimeter is: " << triangle.getPerimeter() << endl;
}