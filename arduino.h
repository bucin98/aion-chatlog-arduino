#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

class arduino
{
public:
	arduino(std::string port);
	~arduino();
	void sendkey(char sendkey);

private:
	HANDLE arduino_handle;
	void send_data(const char* buffer);
};