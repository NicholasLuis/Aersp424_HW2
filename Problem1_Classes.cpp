#include "Problem1_Classes.h"

// This program contains all of the necessary functions for the classes used in question 1



// Question 1.2
void Altimeter::gatherData() {
	std::cout << "Gathering data from Altimeter sensor" << std::endl;
};
void Altimeter::processData() {
	std::cout << "Processing data from Altimeter sensor" << std::endl;
};

void IMU::gatherData() {
	std::cout << "Gathering data from IMU sensor" << std::endl;
};
void IMU::processData() {
	std::cout << "Processing data from IMU sensor" << std::endl;
};

void Thermocouple::gatherData() {
	std::cout << "Gathering data from TC sensor" << std::endl;
};
void Thermocouple::processData() {
	std::cout << "Processing data from TC sensor" << std::endl;
};

// Question 1.3
Sensor* SensorFactory::createSensor(std::string inputStr)
{
	if (inputStr == "Altimeter") {
		Sensor* altimeterPtr = new Altimeter;
		//std::unique_ptr<Sensor> altimeterPtr = std::make_unique<Sensor>();
		return altimeterPtr;
	}
	else if (inputStr == "IMU") {
		Sensor* IMUPtr = new IMU;

		return IMUPtr;

	}
	else if (inputStr == "Thermocouple") {
		Sensor* TCPtr = new Thermocouple;
		return TCPtr;
	}
	else {
		return NULL;
		}
}

// Question 1.4
//AerospaceControlSystem::AerospaceControlSystem(std::mutex *m) { // Construcotr
//	this->mutex = m;
//}

AerospaceControlSystem::~AerospaceControlSystem() { // De-constructor
	for (int i = 0; i < sensorList.size(); i++)
	{
		delete sensorList[i]; // Deletes pointers to avoid memory leak.
	}
	//delete mutex;
}

void AerospaceControlSystem::addSensor(Sensor* sensor_input_Ptr)
{
	this->sensorList.push_back(sensor_input_Ptr);
}

void AerospaceControlSystem::monitorAndAdjust()
{
	for (int i = 0; i < sensorList.size(); i++)
	{
		//mutex->lock();
		sensorList[i]->gatherData();
		//mutex->unlock();

		//mutex->lock();
		sensorList[i]->processData();
		//mutex->unlock();

		//mutex->lock();
		std::cout << "Adjusting controls based on sensor data." << std::endl;
		//mutex->unlock();
	}
}