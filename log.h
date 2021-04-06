#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class ChatLog
{
public:
	bool CheckString(std::string path, std::string word);
	bool CheckVectorString(std::string path, std::vector<std::string>vrword);
	bool CheckFile(std::string path);

private:

};
