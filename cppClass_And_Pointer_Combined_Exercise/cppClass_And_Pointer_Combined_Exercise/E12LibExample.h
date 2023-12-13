#ifndef E12LibExample
#define E12LibExample

#include "iostream"

class DCMotor {
private:
	void setSpeed(uint8_t* buf)
public:
	void getPacket(uint8_t* buffer);
};

class QuadDriver {
private:
	DCMotor* dcMotor[4];
public:
	void attach(DCMotor& dcMotor,uint8_t index);
};

class E12 {
	uint8_t type[8];
	uint64_t address[8];
public:
	void attach();
	void getPacket();
};

#endif