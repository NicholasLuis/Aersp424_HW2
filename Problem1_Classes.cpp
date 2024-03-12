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
	Sensor* sensor = new Sensor();
	return &sensor;
}