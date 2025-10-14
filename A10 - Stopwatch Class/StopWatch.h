#include <time.h>
#pragma once

class StopWatch {
private:
	clock_t startTime;
	clock_t endTime;
	clock_t totalTime;

	// Setters
	void setStartTime();
	void setEndTime();

	// Getters
	clock_t getStartTime();
	clock_t getEndTime();
	float calculateTime(clock_t, clock_t);
	bool isTicking();
public:
	// Constructor
	StopWatch();

	// Other Methods
	bool Start();
	bool Stop();
	void DisplayTimerInfo();
};