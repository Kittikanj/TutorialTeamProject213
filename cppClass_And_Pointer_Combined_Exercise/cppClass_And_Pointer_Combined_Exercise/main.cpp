#include "E12LibExample.h"

void DCMotor::getPacket(uint8_t* buffer) {

}

void QuadDriver::attach(DCMotor& dcMotor, uint8_t index) {
	this->dcMotor[index] = &dcMotor;
}