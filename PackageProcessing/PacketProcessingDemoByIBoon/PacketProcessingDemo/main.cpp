#include <conio.h>
#include<iostream>
#include <chrono>
#include <thread>

#define _growthRate 3.65


uint64_t micros()
{
	uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::high_resolution_clock::now().time_since_epoch())
		.count();
	return us;
}

typedef struct _inputParameter {
	double growthRate = _growthRate;
	double xN = 0;
	uint64_t elapsedTime = 0;
};					
typedef struct _outputParameter {
	double xN1 = 0;
	uint64_t elapsedTime = 0;
};

char c;
class Master;

class Processor {
private:
	

public:
	uint8_t buffer[1024];
	void calculateXN1();
	void transfer(Master& target);

};

Processor processor;

class Master {
private:

	uint64_t iteration = 0;
public:
	uint8_t buffer[1024];
	void setInputParameter();
	void printResult();
	void transfer(Processor& target);
	void iterate();
};

Master master;

int main() {
	
	std::cout << "Hello World" << std::endl;
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	
	((_outputParameter*)(&master.buffer))->xN1 = 0.5;

	while (true) {
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + milliseconds(500));
		master.setInputParameter();
		master.transfer(processor);
		processor.calculateXN1();
		processor.transfer(master);
		master.iterate();
		master.printResult();
		
	}
	
}	 

void Processor::calculateXN1() {
	((_outputParameter*)(this->buffer))->xN1 = ((_inputParameter*)(this->buffer))->growthRate * ((_inputParameter*)(this->buffer))->xN * (1 - ((_inputParameter*)(this->buffer))->xN);
	((_outputParameter*)(this->buffer))->elapsedTime = ((_inputParameter*)(this->buffer))->elapsedTime;
}

void Master::printResult() {
	std::cout << "Current Iteration : " << this->iteration << " , Result XN1 : " << ((_outputParameter*)(this->buffer))->xN1 << " , Processing Time : " << (micros() - ((_outputParameter*)(this->buffer))->elapsedTime) << " us" << std::endl;
}

void Master::setInputParameter() {
	((_inputParameter*)(this->buffer))->xN = ((_outputParameter*)(this->buffer))->xN1;
	((_inputParameter*)(this->buffer))->elapsedTime = micros();
	((_inputParameter*)(this->buffer))->growthRate = _growthRate;
}

void Master::transfer(Processor& target) {
	for (uint16_t i = 0; i < sizeof(_inputParameter); i++) {
		*(uint8_t*)(target.buffer + i) = *(uint8_t*)(this->buffer + i);
	}
}		 

void Processor::transfer(Master& target) {
	for (uint16_t i = 0; i < sizeof(_outputParameter); i++) {
		*(uint8_t*)(target.buffer + i) = *(uint8_t*)(this->buffer + i);
	}
}

void Master::iterate() {
	this->iteration++;
}
