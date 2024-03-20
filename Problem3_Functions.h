#ifndef Problem3_Functions_H
#define Problem3_Functions_H
// This file declares all of the functions/classes needed for Problem 3

#include <queue>

class Aircraft {
	// Decision making: Pilot diverts to different airport if the airport is full
private:

public:
};

class TrafficData {
	// This class tracks if there are planes on the runway & in the traffic pattern
	// This class does NOT make any decisions. It is purely for data organization
private:
	std::queue<Aircraft*> trafficQueue;
	bool runwayStatus;
public:
	TrafficData();

	bool getrunwayStatus();
	void changeRunwayStatus();
	
	int trafficQueueNumber();
	void addToPattern(Aircraft* AnotherPlane);
	void removeFromPattern();
};

#endif