#pragma once
#include <time.h>

class Timer {
private:
	clock_t time;

public:
	// Constuctor
	Timer();

	// Start Timer
	bool start();

	// End timer
	bool stop();

	// Display Timer
	void display();
};