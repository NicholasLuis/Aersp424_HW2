#include "Problem2_Functions.h"
#include <iostream>
#include <chrono>
//#include <thread> Already defined in Problem2_Functions.h

// This file defines all of the classes/functions needed for problem 2

Robot::Robot(int number, std::mutex *m) {
	this->ID_Number = number;
	this->mutex = m;
}

void Robot::operate() {
	t1 = std::thread(&Robot::work, this);
}

void Robot::joinThread() {
	t1.join();
}

void Robot::work() {
	mutex->lock(); // Need mutex because terminal output is a shared resource
	std::cout << "Robot " << this->ID_Number << " is doing their task." << std::endl;
	mutex->unlock();
	
	std::this_thread::sleep_for(std::chrono::seconds(6)); // 6 seconds total to pick up tools, work, and put it back
	
	mutex->lock();
	std::cout << "Robot " << this->ID_Number << " has completed their task." << std::endl;
	mutex->unlock();
}