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
	std::mutex* PrintMutex;
	std::mutex* DataMutex;
	std::queue<Aircraft*>* trafficQueue = new std::queue<Aircraft*>;
	bool* runwayStatus = new bool;

	std::thread threadAircraft;
public:
	Aircraft(int num); // Constructor

	void initiateContact(bool* contactPtr);
	void operate(); // Command that has all of the planes operate independently
	void setMutexes(std::mutex* mutex1, std::mutex* mutex2);
	void setDataShare(bool* sharedData1, std::queue<Aircraft*>* sharedData2);
	void setAircraftNumber(int num);
};

class ATC {
private:
	std::mutex* PrintMutex = new std::mutex;
	std::mutex* DataMutex = new std::mutex;
	bool* runwayStatus = new bool;
	std::queue<Aircraft*>* trafficQueue = new std::queue<Aircraft*>;

	std::thread threadATC;

	bool isAsleep; // keeps track of if the ATC is asleep
	bool isBusy; // keeps track of if the ATC is already talking to someone
	bool* initiatingContact = new bool;
public: 
	ATC(); // constructor

	void setMutexes(std::mutex* mutex1, std::mutex* mutex2);
	void setDataShare(bool* sharedData1, std::queue<Aircraft*>* sharedData2);
	void setContactPtr(bool* contactPtr);
	void initiateContact();
	std::string getStatus();
	void operate();

};

//class TrafficData {
//	// This object is a shared resource that has information about the traffic pattern, runway status, etc.
//private:
//	std::queue<Aircraft*> trafficQueue;
//	bool runwayStatus;
//public:
//	TrafficData();
//
//	bool getrunwayStatus();
//	void changeRunwayStatus();
//	
//	int trafficQueueNumber();
//	void addToPattern(Aircraft* AnotherPlane);
//	void removeFromPattern();
//};

#endif