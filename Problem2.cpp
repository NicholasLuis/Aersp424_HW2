#include "Problem2_Functions.h"
#include <iostream>
#include <vector>
#include <chrono>
//#include <mutex>	Already defined in Problem2_Functions.h
//#include <thread> Already defined in Problem2_Functions.h

int main()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	std::mutex* m = new std::mutex;

	// Creates 5 different robot objects, which all share the same mutex object
	Robot robots[5] = { Robot(1, m), Robot(2, m) , Robot(3, m) , Robot(4, m) , Robot(5, m) };

	robots[0].operate();
	robots[2].operate();
	robots[0].joinThread();
	robots[2].joinThread();

	robots[1].operate();
	robots[3].operate();
	robots[1].joinThread();
	robots[3].joinThread();

	robots[4].operate();
	robots[4].joinThread();

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
	std::cout << "duration : " << duration.count() << " seconds" << std::endl;

	delete m;
	return 0;
}