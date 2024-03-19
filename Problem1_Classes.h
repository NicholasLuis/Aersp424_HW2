#ifndef Problem1_Classes_H
#define Problem1_Classes_H

#include <iostream>
#include <vector>
#include <mutex>

// This program contains all of the necessary classes used in question 1

// Problem 1.1
class Sensor {
public:
	virtual void gatherData() = 0;
	virtual void processData() = 0;
};

// Problem 1.2
class Altimeter : public Sensor { 
public:
	void gatherData(); 
	void processData();
};
class IMU : public Sensor {
public:
	void gatherData();
	void processData();
};
class Thermocouple : public Sensor {
public:
	void gatherData();
	void processData();
};

// Question 1.3
class SensorFactory {
public:
	static Sensor* createSensor(std::string inputStr);
};

// Question 1.4
class AerospaceControlSystem {
private:
	std::vector<Sensor*> sensorList;
	//std::mutex* mutex = new std::mutex;
public:
	void addSensor(Sensor* sensorPtr);
	void monitorAndAdjust();

	// AerospaceControlSystem(std::mutex *m); // Constructor that accepts a mutex
	~AerospaceControlSystem(); // De-constructor
};

#endif