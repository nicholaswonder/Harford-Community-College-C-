#pragma once

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <math.h>

using namespace std;

class Vector {

private:
	double _v_x;
	double _v_y;
	double _magnitude;

	// Helper method
	void CalculateMagnitude();
	
public:

	// Contructor
	Vector();
	Vector(double _v_x, double _v_y);

	// Setters
	void SetVX(double _v_x);
	void SetVY(double _v_y);
	
	// Getters
	double GetVX();
	double GetVY();
	double GetMagnitude();

	// Operations
	Vector AddVector(Vector addMe);
	Vector SubtractVector(Vector subtractMe);
	Vector operator+(const Vector&);
	Vector operator-(Vector const&);
	void operator=(Vector&);
	friend ostream& operator<<(ostream&, const Vector&);

	// Display
	void Display();

};

#endif
