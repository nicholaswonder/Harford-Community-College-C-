// Function definitions

#include "Triangle Spec.h"
#include <cmath>

using namespace std;

// Constructor
Triangle::Triangle() {
	adjacent = 3;
	opposite = 4;
	hypotonuse = 0;
}

// Getters
float Triangle::getAdjacent() {
	return adjacent;
	getHypotonuse();
}

float Triangle::getOpposite() {
	return opposite;
	getHypotonuse();
}

float Triangle::getHypotonuse() {
	hypotonuse = sqrt(pow(adjacent, 2) + pow(opposite, 2));
	return hypotonuse;
}

float Triangle::getArea() {
	return ((opposite * adjacent) / 2);
}

float Triangle::getPerimeter() {
	return (adjacent + opposite + hypotonuse);
}

// Setters
bool Triangle::setAdjacent(float newValue) {
	if (cin.fail() == true) {
		cin.clear();
		cout << "Error: Invalid Input" << endl;
	}
	else if (newValue <= 0) {
		cout << "Error: Value must be greater than 0" << endl;
		return false;
	}
	else {
		adjacent = newValue;
		return true;
	}
}

bool Triangle::setOpposite(float newValue) {
	if (cin.fail() == true) {
		cin.clear();
		cout << "Error: Invalid Input" << endl;
	}
	else if (newValue <= 0) {
		cout << "Error: Value must be greater than 0" << endl;
		return false;
	}
	else {
		opposite = newValue;
		return true;
	}
}

bool Triangle::setHypotonuse(float newValue) {
	hypotonuse = newValue;
	
	return true;
}