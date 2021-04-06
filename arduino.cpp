#include "arduino.h"


arduino::arduino(std::string port)
{
	std::string nPort = "\\.\\COM" + port;

	this->arduino_handle = CreateFileA(
		nPort.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		0,
		nullptr,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);

	if (arduino_handle == INVALID_HANDLE_VALUE)
		return;

	DCB dcb = { };
	dcb.DCBlength = sizeof(dcb);
	if (!GetCommState(arduino_handle, &dcb))
		return;

	dcb.BaudRate = CBR_9600;
	dcb.ByteSize = 8;
	dcb.StopBits = ONESTOPBIT;
	dcb.Parity = NOPARITY;

	if (!SetCommState(arduino_handle, &dcb))
		return;

	COMMTIMEOUTS cto = { };
	cto.ReadIntervalTimeout = 50;
	cto.ReadTotalTimeoutConstant = 50;
	cto.ReadTotalTimeoutMultiplier = 10;
	cto.WriteTotalTimeoutConstant = 50;
	cto.WriteTotalTimeoutMultiplier = 10;
	if (!SetCommTimeouts(arduino_handle, &cto))
		return;

	std::cout << "arduino connect" << std::endl;
}

arduino::~arduino()
{
	CloseHandle(this->arduino_handle);
}

void arduino::sendkey(char sendkey)
{
	std::string key = std::to_string(sendkey);
	arduino::send_data(key.c_str());
}

void arduino::send_data(const char* buffer)
{
	std::string str = buffer;
	size_t sz = str.length() + 1;
	WriteFile(this->arduino_handle, buffer, sz, NULL, nullptr);
}
