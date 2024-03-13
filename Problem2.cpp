#include "Problem2_Functions.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

int main()
{
	auto startTime = std::chrono::high_resolution_clock::now();

	Robot robots[5] = { Robot(1), Robot(2) , Robot(3) , Robot(4) , Robot(5) };

	robots[0].operate();
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // buffer because of resource sharing
	robots[2].operate();
	robots[0].joinThread();
	robots[2].joinThread();

	robots[1].operate();
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); // buffer because of resource sharing
	robots[3].operate();
	robots[1].joinThread();
	robots[3].joinThread();

	robots[4].operate();
	robots[4].joinThread();

	//std::thread t1, t2; // Only two robots can work at at time
	//t1 = std::thread(&robots[1]);

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
	std::cout << "duration : " << duration.count() << " seconds" << std::endl;
	return 0;
}

/*
QUESTION 5: What issues may happen if the robot that finished the
task is assigned a new task immediately? And what will be a potential
solution for the issues?

	The 5 second delay accounts for the time it takes to do the task and put the tools back.
	If the robot has a new task to do immediately, then it shouldn't waste time putting down the tool.
	A potential solution is to figure out how much time is spent actually doing the task and have a separate
	function that accoutns for the time it takes to put down the tool (if necessary)
*/