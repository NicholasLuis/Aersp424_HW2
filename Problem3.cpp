#include "Problem3_Functions.h"
#include <vector>
#include <thread>

int main() 
{
	// Creates shared resources
	std::queue<Aircraft*>* trafficQueue= new std::queue<Aircraft*>;
	bool* runwayStatus = new bool;
	*runwayStatus = false;
	bool* initiatingContact = new bool;
	*initiatingContact = false;

	// Creates 1 mutex for the output window and 1 mutex for the traffic data (both shared resources)
	std::mutex* printMutex = new std::mutex; 
	std::mutex* dataMutex = new std::mutex;
	
	// Creates 10 Aircraft, 11 threads, 1 Air Traffic Controller
	Aircraft* Aircrafts[10];
	std::thread threadList[11];
	ATC ATC1;

	// Resource sharing 
	for (int i = 0; i < 10; i++)
	{
		Aircrafts[i] = new Aircraft(i); // Creates 10 aircraft objects, each of which has a designation number
		Aircrafts[i]->setMutexes(printMutex, dataMutex);
		Aircrafts[i]->setDataShare(runwayStatus, trafficQueue);

	}
	ATC1.setMutexes(printMutex, dataMutex);
	ATC1.setDataShare(runwayStatus, trafficQueue);

	// Operate
	for (int i = 0; i < 10; i++)
	{
		Aircrafts[i]->operate();
	}
	threadList[10] = std::thread(&ATC::operate, &ATC1);


	return 0; 
}