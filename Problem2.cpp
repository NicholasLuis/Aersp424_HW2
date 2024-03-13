#include "Problem2_Functions.h"
#include <thread>
#include <vector>
#include <chrono>

int main()
{
	std::vector<Robot> robots{ Robot(1), Robot(2) , Robot(3) , Robot(4) , Robot(5) }; // creates 5 robots
	
	std::thread t1(robots[1].work);


	return 0;
}