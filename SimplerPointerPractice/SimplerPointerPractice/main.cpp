#include "iostream"


#define EXAMPLE // �����鹺�÷Ѵ����͡�����ͧ��¹�ͧ

// Code for Practice
#ifndef EXAMPLE

uint8_t buffer[24];
typedef struct packetStyle {
	uint32_t studentID = 0x63010298;
	uint8_t a = 0xFF; //�Ţ�ҹ 16
	uint8_t b = 0x34; //�Ţ�ҹ 16
	uint8_t c = 145; //�Ţ�ҹ 10
};
packetStyle packet;

void copyStruct2Buffer(uint8_t* buffer, packetStyle& packet) {
	//��¹�鴵ç���
}
int main() {

	copyStruct2Buffer(buffer, packet);

	for (uint8_t i = 0; i < 24; i++) {
		std::cout << "Byte : " << unsigned(i) << ", Value : " << std::hex << unsigned(buffer[i]) << std::endl;
	}
}


#endif

//Code ���

#ifdef EXAMPLE

uint8_t buffer[24];
typedef struct packetStyle {
	uint32_t studentID = 0x63010298;
	uint8_t a = 0xFF; //�Ţ�ҹ 16
	uint8_t b = 0x34; //�Ţ�ҹ 16
	uint8_t c = 145; //�Ţ�ҹ 10
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