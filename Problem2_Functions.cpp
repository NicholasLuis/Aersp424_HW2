#include "Problem2_Functions.h"
#include <iostream>
#include <chrono>

// This file defines all of the classes/functions needed for problem 2

Robot::Robot(int number) {
	this->ID_Number = number;
}

void Robot::work() {
	std::this_thread::sleep_for(std::chrono::seconds(6)); // 6 seconds total to pick up tools, work, and put it back
	std::cout << "Robot " << ID_Number << " is doing their task." << std::endl;
}