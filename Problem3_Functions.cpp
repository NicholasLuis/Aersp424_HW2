// This file initializes all of the function/classes definitions needed for Problem 3
#include "Problem3_Functions.h"

// Aircraft Class
	void Aircraft::setMutexes(std::mutex* mutex1, std::mutex* mutex2)
	{
		PrintMutex = mutex1;
		DataMutex = mutex2;
	}
	void Aircraft::setDataShare(TrafficData* sharedData) 
	{
		trafficData = sharedData;
	}
	void setAircraftNumber(int num);
	void Aircraft::operate() // this will run independently
	{
		if (trafficData->trafficQueueNumber() >= 3) // Checks if the traffic pattern is full
		{
			PrintMutex->lock();
			std::cout << "The traffic pattern is full. Aircraft # " << AircraftNumber << " is going to a different airport" << std::endl;
			PrintMutex->unlock();

		}
	}

// ATC Class
	void ATC::setMutexes(std::mutex* mutex1, std::mutex* mutex2) // ATC constructor
	{
		PrintMutex = mutex1;
		DataMutex = mutex2;
	}
	void ATC::setDataShare(TrafficData* sharedData)
	{
		trafficData = sharedData;
	}
	void operate()
	{

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