#ifndef Problem3_Functions_H
#define Problem3_Functions_H
// This file declares all of the functions/classes needed for Problem 3

#include <queue>
#include <iostream>
#include <thread>
#include <mutex>

class Aircraft {
private:
	int AircraftNumber; 
	std::mutex* PrintMutex = new std::mutex;
	std::mutex* DataMutex = new std::mutex;
	TrafficData* trafficData = new TrafficData;

	std::thread threadAircraft;
public:
	void initiateContact(ATC* ATC_Pointer);
	void operate(); // Command that has all of the planes operate independently
	void setMutexes(std::mutex* mutex1, std::mutex* mutex2);
	void setDataShare(TrafficData* sharedData);
	void setAircraftNumber(int num);
};

class ATC {
private:
	std::mutex* PrintMutex = new std::mutex;
	std::mutex* DataMutex = new std::mutex;
	TrafficData* trafficData = new TrafficData;

	std::thread threadATC;

	bool isAsleep;
	bool isBusy; // keeps track if the 
public: 
	std::string getStatus();
	void operate();
	void setMutexes(std::mutex* mutex1, std::mutex* mutex2);
	void setDataShare(TrafficData* sharedData);
};

class TrafficData {
	// This object is a shared resource that has information about the traffic pattern, runway status, etc.
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