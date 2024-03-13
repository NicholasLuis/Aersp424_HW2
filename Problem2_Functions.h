#ifndef Problem2_Functions_H
#define Problem2_Functions_H

#include <thread>

// This file declares all of the classes/functions needed for problem 2

void test();

class Robot {
public: 
	Robot(int number);
	void operate();
	void joinThread();
	void work();

private:
	int ID_Number;
	std::thread t1;
};

#endif
