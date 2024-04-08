// This file initializes all of the function/classes definitions needed for Problem 3
#include "Problem3_Functions.h"

// Aircraft Class
	Aircraft::Aircraft(std::mutex* mutex1, std::mutex* mutex2) // Aircraft constructor
	{
		this->PrintMutex = mutex1;
		this->DataMutex = mutex2;
	}

// ATC Class
	ATC::ATC(std::mutex* mutex1, std::mutex* mutex2) // ATC constructor
	{
		this->PrintMutex = mutex1;
		this->DataMutex = mutex2;
	}

// "Traffic Data" Class
	TrafficData::TrafficData() { // Default Constructor
		this->runwayStatus = false; // No planes on runway to start
	};

	// Runway-related information
	bool TrafficData::getrunwayStatus() { return this->runwayStatus; }
	void TrafficData::changeRunwayStatus() { this->runwayStatus = !runwayStatus; }

	// Traffic-Pattern-related information
	int TrafficData::trafficQueueNumber() { return this->trafficQueue.size(); }
	void TrafficData::addToPattern(Aircraft* AnotherPlane) { 
		this->trafficQueue.push(AnotherPlane); // Adds a plane to the queue
	}
	void TrafficData::removeFromPattern() {
		this->trafficQueue.pop(); // Removes the first plane in the queue
	}