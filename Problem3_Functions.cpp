// This file initializes all of the function/classes definitions needed for Problem 3
#include "Problem3_Functions.h"

// Aircraft Class
	Aircraft::Aircraft() // Constructor
	{

	}
	void Aircraft::setMutexes(std::mutex* mutex1, std::mutex* mutex2)
	{
		PrintMutex = mutex1;
		DataMutex = mutex2;
	}
	void Aircraft::setDataShare(bool* sharedData1, std::queue<Aircraft*>* sharedData2)
	{
		runwayStatus = sharedData1;
		trafficQueue = sharedData2;
	}
	void Aircraft::setAircraftNumber(int num) 
	{
		AircraftNumber = num;
	}
	void Aircraft::operate() // this will run independently
	{
		while (true) { // Thread operates the Aircraft forever

			if (trafficQueue->size() >= 3) // Checks if the traffic pattern is full
			{
				PrintMutex->lock();
				std::cout << "The traffic pattern is full. Aircraft # " << AircraftNumber << " is going to a different airport" << std::endl;
				PrintMutex->unlock();
			}
		}
	}


// ATC Class
	ATC::ATC() // Constructor
	{
		isAsleep = false;
		isBusy = false;
	}
	void ATC::setMutexes(std::mutex* mutex1, std::mutex* mutex2) // ATC constructor
	{
		PrintMutex = mutex1;
		DataMutex = mutex2;
	}
	void ATC::setDataShare(bool* sharedData1, std::queue<Aircraft*>* sharedData2)
	{
		runwayStatus = sharedData1;
		trafficQueue = sharedData2;
	}
	void ATC::setContactPtr(bool* contactPtr)
	{
		initiatingContact = contactPtr;
	}
	void ATC::initiateContact() 
	{
		isAsleep = false; // Wakes up the ATC
	}
	std::string ATC::getStatus()
	{
		if (isAsleep)
		{
			return "sleeping";
		}
		else if (isBusy)
		{
			return "busy";
		}
	}
	void ATC::operate()
	{
		while (true) { // Thread operates the ATC object forever
		
			// Sets the pointer back to false (the ATC is available for contacting)			

		}

	}


//// "Traffic Data" Class
//	TrafficData::TrafficData() { // Default Constructor
//		this->runwayStatus = false; // No planes on runway to start
//	};
//
//	// Runway-related information
//	bool TrafficData::getrunwayStatus() { return this->runwayStatus; }
//	void TrafficData::changeRunwayStatus() { this->runwayStatus = !runwayStatus; }
//
//	// Traffic-Pattern-related information
//	int TrafficData::trafficQueueNumber() { return this->trafficQueue.size(); }
//	void TrafficData::addToPattern(Aircraft* AnotherPlane) { 
//		this->trafficQueue.push(AnotherPlane); // Adds a plane to the queue
//	}
//	void TrafficData::removeFromPattern() {
//		this->trafficQueue.pop(); // Removes the first plane in the queue
//	}