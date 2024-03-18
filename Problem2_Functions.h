#ifndef Problem2_Functions_H
#define Problem2_Functions_H

#include <thread>
#include <mutex>

// This file declares all of the classes/functions needed for problem 2

void test();

class Robot {
public: 
	Robot(int number, std::mutex *m);
	void operate();
	void joinThread();
	void work();

private:
	int ID_Number;
	std::thread t1;
	std::mutex* mutex = new std::mutex;
};

#endif
