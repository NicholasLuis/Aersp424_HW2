#ifndef Problem1_Classes_H
#define Problem1_Classes_H

#include <iostream>

// This program contains all of the necessary classes used in question 1

// Problem 1.1
class Sensor {
public:
	virtual void gatherData() = 0;
	virtual void processData() = 0;
};

// Problem 1.2
class Altimeter : public Sensor { 
	void gatherData(); 
	void processData();
};
class IMU : public Sensor {
	void gatherData();
	void processData();
};
class Thermocouple : public Sensor {
	void gatherData();
	void processData();
};

class SensorFactory {
	static Sensor* createSensor(std::string inputStr) {
		
	}
};

#endif