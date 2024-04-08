#include "Problem3_Functions.h"
#include <vector>
#include <thread>

int main() {
	// Creates 1 mutex for the output window and 1 mutex for the traffic data (both shared resources)
	std::mutex* printMutex = new std::mutex; 
	std::mutex* dataMutex = new std::mutex;
	
	// Creates 10 Aircraft, 11 threads, 1 Air Traffic Controller, 1 shared data resource
	Aircraft Aircrafts[10];
	std::thread threadList[11];
	ATC ATC1;
	TrafficData* trafficData = new TrafficData;

	// Resource sharing 
	for (int i = 0; i < 10; i++)
	{
		Aircrafts[i].setMutexes(printMutex, dataMutex);
		Aircrafts[i].setDataShare(trafficData);

	}
	ATC1.setMutexes(printMutex, dataMutex);
	ATC1.setDataShare(trafficData);

	// Operate
	threadList[0] = std::thread(&ATC::operate, ATC1);
	for (int i = 0; i < 10; i++)
	{
		Aircrafts[i].operate();
		threadList[i+1] = std::thread(&ATC::operate, ATC1);
	}

	return 0;
}



/*
PSEUDOCODE for all files pertaining to Problem 3

>	Initialize global variables:
		- [runWay status] (bool) that tracks if there is a plane on the runway

>	Initialize multithreading
		- Each plane + ATC has its own thread to watch for status changes, requests, etc.

>	Traffic data object
		- Private [traffic pattern] (queue container of Plane pointers) tracks how many/which airplanes are in the pattern already
		- Private [runway status] (bool) tracks if there is a plane on the runway
		- bool function that gets the runway status
		- void function that changes the runway status
		- int function that gets number of planes in the pattern
		- void function that adds planes pointers to queue { .push( [plane pointer]  ) }
		- void function that removes planes from the queue { .pop() }

		- Create 1 Traffic pattern object

>	Plane objects
		- [Designation number] (int) accepted in constructor to keep track of it
		- [request landing] (bool) that also prints out this request
		- [redirection] (bool) tracks if the plane is redirected
		- Void function that requests landing
			-> If landing request = true, print out that it is landing
			-> Else wait until landing granted
		- Void function that grants landing (called by ATC via object pointer)
		- Void function that redirects plane (called vy ATC via object pointer)
		
		- Create 10 Plane objects

>	ATC object
		- void function that accepts [plane (object)], [landing request (bool)], and [landing clearance (bool)] pointers to know which plane to grant a landing to
		- [isAsleep] (bool) variable 
		- Create 1 ATC object


*** Don't forget to delete pointers to avoid memory leaks

	Thread for each plane + atc
*/