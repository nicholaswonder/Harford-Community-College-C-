#include "Sort Class.h"
#include <iostream>

using namespace std;

Sort::Sort() {
	// Eventually, this array will be filled with the numbers given from the files
	// Probably will be best to make this a pointer array to make a dynamically sized array
	// Made this for testing purposes
	dataGiven = new int[]{ 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	numOfItems = 21;
}

Sort::Sort(ifstream& file) {
	file.clear();
	file.seekg(0);
	int storage;
	numOfItems = 0;
	do {
		file >> storage;
		numOfItems++;
	} while (file.peek() != EOF);

	dataGiven = new int[numOfItems];
	file.clear();
	file.seekg(0);

	for (int i = 0; i < numOfItems; i++) {
		file >> storage;
		dataGiven[i] = storage;
	}
}
 
// Bubble sort function
bool Sort::bubbleSort() {
	bool swapped = true;
	int storage = 0;
	time.start();
	while (swapped == true) {
		swapped = false;
		for (int i = 0; i < (numOfItems - 1); i++) {
			int j = i + 1;
			if (dataGiven[i] > dataGiven[j]) {
				storage = dataGiven[i];
				dataGiven[i] = dataGiven[j];
				dataGiven[j] = storage;
				swapped = true;
			}
		}
	}
	time.stop();
	cout << "Bubble sorting " << numOfItems << " elements took "; time.display();
	return true;
}

bool Sort::selectSort() {
	time.start();
	for (int i = 0; i < (numOfItems - 1); i++) {
		int Min = i;
		for (int j = i + 1; j < numOfItems; j++) {
			if (dataGiven[Min] > dataGiven[j]) {
				Min = j;
			}
		}

		int storage = dataGiven[i];
		dataGiven[i] = dataGiven[Min];
		dataGiven[Min] = storage;
	}
	time.stop();
	cout << "Selection sorting " << numOfItems << " elements took "; time.display();
	return true;
}

bool Sort::insertSort() {
	int storage = 0;
	time.start();
	for (int i = 1; i < numOfItems; i++) {
		for (int i = 1; i < numOfItems; i++) {
			int j = i - 1;
			storage = dataGiven[i];
			while (dataGiven[j] > storage && j >= 0) {
				dataGiven[j + 1] = dataGiven[j];
				j--;
			}
			dataGiven[j + 1] = storage;
		}
	}
	time.stop();
	cout << "Insertion sorting " << numOfItems << " elements took "; time.display();
	return true;
}

// Display Function for testing purposes
void Sort::displayArray() {
	for (int i = 0; i < numOfItems; i++) {
		cout << dataGiven[i] << "   " << i << endl;
	}
}

// Destructor
Sort::~Sort() {
	delete dataGiven;
	dataGiven = NULL;
}