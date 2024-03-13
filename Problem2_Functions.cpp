#include "Problem2_Functions.h"
#include <thread>
#include <iostream>
#include <chrono>

// This file defines all of the classes/functions needed for problem 2

Robot::Robot(int number) {
	this->ID_Number = number;
}

void Robot::operate() {
	t1 = std::thread(&Robot::work, this);
}

void Robot::joinThread() {
	t1.join();
}

void Robot::work() {
	std::cout << "Robot " << this->ID_Number << " is doing their task." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(6)); // 6 seconds total to pick up tools, work, and put it back
	std::cout << "Robot " << this->ID_Number << " has completed their task." << std::endl;
}