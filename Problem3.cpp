#include "Problem3_Functions.h"
#include <mutex>

int main() {
	// Creates 1 mutex for the output window and 1 mutex for the traffic data (both shared resources)
	std::mutex* printMutex = new std::mutex; 
	std::mutex* dataMutex = new std::mutex;
	
	// Creates 10 Aircraft and 1 Air Traffic Controller
	Aircraft Plane1(printMutex, dataMutex), Plane2(printMutex, dataMutex), Plane3(printMutex, dataMutex), 
			 Plane4(printMutex, dataMutex), Plane5(printMutex, dataMutex), Plane6(printMutex, dataMutex), 
			 Plane7(printMutex, dataMutex), Plane8(printMutex, dataMutex), Plane9(printMutex, dataMutex),
			 Plane10(printMutex, dataMutex);

	ATC ATC1(printMutex, dataMutex);
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