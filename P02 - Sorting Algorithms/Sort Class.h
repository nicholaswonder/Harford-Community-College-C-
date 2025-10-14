#pragma once
#include <string>
#include <fstream>
#include "Timer Class.h"

using namespace std;

class Sort {
private:
	int* dataGiven;
	int numOfItems;
	Timer time;

public:
	// Constructor
	Sort();
	
	// Parameterized Constructor
	Sort(ifstream&);

	// Bubblesort function
	bool bubbleSort(); 

	// Selection sort function
	bool selectSort();

	// Insertion sort function
	bool insertSort();

	// Display function for testing reasons
	void displayArray();

	// Destructor
	~Sort();
};