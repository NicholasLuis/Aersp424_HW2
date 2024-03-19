#include "Problem1_Classes.h";
#include <thread>;
#include <mutex>;

int main()
{
	// Question 1.5
	//std::thread t1, t2, t3;
	//std::mutex* m = new std::mutex;
	SensorFactory snsrFactory;
	AerospaceControlSystem cntrlSys;

	// Multi-threading for creating the different sensors
	//t1 = std::thread(&AerospaceControlSystem::addSensor, cntrlSys, snsrFactory.createSensor("Altimeter"));
	//t2 = std::thread(&AerospaceControlSystem::addSensor, cntrlSys, snsrFactory.createSensor("IMU"));
	//t3 = std::thread(&AerospaceControlSystem::addSensor, cntrlSys, snsrFactory.createSensor("Thermocouple"));

	cntrlSys.addSensor(snsrFactory.createSensor("Altimeter"));
	cntrlSys.addSensor(snsrFactory.createSensor("IMU"));
	cntrlSys.addSensor(snsrFactory.createSensor("Thermocouple"));

	cntrlSys.monitorAndAdjust();

	//t1.join();
	//t2.join();
	//t3.join();
	cntrlSys.~AerospaceControlSystem(); // Calls deconstructor to delete pointers to avoid memory leak.
	return 0;
}