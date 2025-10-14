#include "Specifications.h"

// Helper Method
void Vector::CalculateMagnitude() {
	this->_magnitude = sqrt(pow(abs(this->_v_x), 2) + pow(abs(this->_v_y), 2));
}

// Constructors 
Vector::Vector() { 
	this->_v_x = 0.0; 
	this->_v_y = 0.0; 
	CalculateMagnitude(); 
}

Vector::Vector(double _v_x, double _v_y) { 
	this->_v_x = _v_x; 
	this->_v_y = _v_y; 
	CalculateMagnitude(); 
}

// Setters 
void Vector::SetVX(double _v_x) { 
	this->_v_x = _v_x; 
	CalculateMagnitude(); 
}

void Vector::SetVY(double _v_y) { 
	this->_v_y = _v_y; 
	CalculateMagnitude(); 
}

// Getters
double Vector::GetVX() {
	return this->_v_x;
}

double Vector::GetVY() {
	return this->_v_y;
}

double Vector::GetMagnitude() {
	return this->_magnitude;
}

// Operations
Vector Vector::AddVector(Vector addMe) {
	// Create a temp vector
	Vector returnMe;

	// Add corresponding vector components
	returnMe.SetVX(this->_v_x + addMe.GetVX());
	returnMe.SetVY(this->_v_y + addMe.GetVY());

	// Return the temp Vector
	return returnMe;
}

Vector Vector::SubtractVector(Vector subtractMe) {
	// Create a temp vector
	Vector returnMe;

	// Subract vector components
	returnMe.SetVX(this->_v_x + subtractMe.GetVX());
	returnMe.SetVY(this->_v_y - subtractMe.GetVY());

	// Return temp Vector
	return returnMe;
}

// Operator Overloads
Vector Vector::operator+(Vector const& v2) {
	return this->AddVector(v2);
}

Vector Vector::operator-(Vector const& v2) {
	return this->SubtractVector(v2);
}

void Vector::operator=(Vector& v2) {
	this->SetVX(v2.GetVX());
	this->SetVY(v2.GetVY());
}

ostream& operator<<(ostream& os, const Vector& v2) {
	os << "<" << v2._v_x << ", " << v2._v_y << ">" << endl;
	return os;
}

// Display
void Vector::Display() {
	cout << "<" << this->_v_x << ", " << this->_v_y << ">" << endl;
}