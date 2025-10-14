#pragma once
// Function Prototypes

#include <iostream>

class Triangle {
private:
	float adjacent;
	float opposite;
	float hypotonuse;

public:
	// Constructor
	Triangle();

	// Getters
	float getAdjacent();
	float getOpposite();
	float getHypotonuse();
	float getArea();
	float getPerimeter();

	// Setters
	bool setAdjacent(float);
	bool setOpposite(float);
	bool setHypotonuse(float);
};