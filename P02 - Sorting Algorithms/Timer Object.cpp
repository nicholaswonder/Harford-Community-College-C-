#include "Timer Class.h"
#include <iostream>

using namespace std;

Timer::Timer() {
	time = 0;
}

bool Timer::start() {
	// Resets the timer everytime start is called anyways
	time = clock();
	return true;
}

bool Timer::stop() {
	time = clock() - time;
	return true;
}

void Timer::display() {
	cout << time << " milliseconds" << endl;
}