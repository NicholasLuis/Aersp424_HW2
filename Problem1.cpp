#include "Problem1_Classes.h";
#include <thread>;
#include <mutex>;

int main()
{
	// Question 1.5
	std::thread t1, t2, t3;
	AerospaceControlSystem cntrlSys;
	SensorFactory snsrFactory;

	t1 = std::thread( &cntrlSys::addSensor(snsrFactory.createSensor("Altimeter")) );
	cntrlSys.addSensor(snsrFactory.createSensor("IMU"));
	cntrlSys.addSensor(snsrFactory.createSensor("Thermocouple"));

	cntrlSys.monitorAndAdjust();

	return 0;
}