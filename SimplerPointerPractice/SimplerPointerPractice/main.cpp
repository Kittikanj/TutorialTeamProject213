#include "iostream"


#define EXAMPLE // คอมเม้นบรรทัดนี้ออกเพื่อลองเขียนเอง

// Code for Practice
#ifndef EXAMPLE

uint8_t buffer[24];
typedef struct packetStyle {
	uint32_t studentID = 0x63010298;
	uint8_t a = 0xFF; //เลขฐาน 16
	uint8_t b = 0x34; //เลขฐาน 16
	uint8_t c = 145; //เลขฐาน 10
};
packetStyle packet;

void copyStruct2Buffer(uint8_t* buffer, packetStyle& packet) {
	//เขียนโค้ดตรงนี้
}
int main() {

	copyStruct2Buffer(buffer, packet);

	for (uint8_t i = 0; i < 24; i++) {
		std::cout << "Byte : " << unsigned(i) << ", Value : " << std::hex << unsigned(buffer[i]) << std::endl;
	}
}


#endif

//Code เฉลย

#ifdef EXAMPLE

uint8_t buffer[24];
typedef struct packetStyle {
	uint32_t studentID = 0x63010298;
	uint8_t a = 0xFF; //เลขฐาน 16
	uint8_t b = 0x34; //เลขฐาน 16
	uint8_t c = 145; //เลขฐาน 10
};
packetStyle packet;

void copyStruct2Buffer(uint8_t* buffer, packetStyle& packet) {
	for (uint8_t i = 0; i < sizeof(packetStyle); i++) {
		buffer[i] = *((uint8_t*)(&packet + i);
	}
}
int main() {
	
	copyStruct2Buffer(buffer,packet);

	for (uint8_t i = 0; i < 24; i++) {
		std::cout << "Byte : " << unsigned(i) << ", Value : " << std::hex << unsigned(buffer[i]) << std::endl;
	}
}

#endif