#include "StopWatch.h"
#include <time.h>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

StopWatch::StopWatch() {
	totalTime = 0.0;
	startTime = 0.0;
	endTime = 0.0;
}

// Setters
void StopWatch::setStartTime() {
	startTime = clock();
}

void StopWatch::setEndTime() {
	endTime = clock();
}

// Getters
clock_t StopWatch::getStartTime() {
	return startTime;
}

clock_t StopWatch::getEndTime() {
	return endTime;
}

// Start function
bool StopWatch::Start() {
	if (isTicking() == false) {
		setStartTime();
		return true;
	}
	else if (isTicking() == true) {
		return false;
	}
}

// Stop Function
bool StopWatch::Stop() {
	if (isTicking() == true) {
		setEndTime();
		return true;
	}
	else if (isTicking() == false) {
		return false;
	}
}

// Is ticking tester
bool StopWatch::isTicking() {
	if (getStartTime() == 0) {
		return true;
	}
	else if (getStartTime() != 0) {
		return false;
	}
}

// Basic math to calculate the total time that passed
float StopWatch::calculateTime(clock_t startTime, clock_t endTime) {
	float seconds = 0;
	float miliseconds = 0;
	float timeElapsed = 0;
	totalTime = (endTime - startTime);
	seconds = totalTime / CLOCKS_PER_SEC;
	miliseconds = (totalTime % CLOCKS_PER_SEC) / 1000.0;
	timeElapsed = seconds + miliseconds;
	return timeElapsed;
}

// Display function
void StopWatch::DisplayTimerInfo() {
	cout << showpoint << setprecision(4) << calculateTime(getStartTime(), getEndTime()) << " seconds have passed" << endl;
	cout << "Press any key to continue" << endl;
}