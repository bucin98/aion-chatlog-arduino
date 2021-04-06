#include "log.h"

bool ChatLog::CheckString(std::string path, std::string word)
{
	bool status = false;
	
	std::string str;
	std::ifstream info;

	info.open(path, std::ifstream::in);
	while (info.eof() == false)
	{
		std::getline(info, str);


		if (str.find(word) != std::string::npos)
		{
			info.close();
			status = true;
			break;
		}
		else
		{
			status = false;
		}
	}

	return status;
}

bool ChatLog::CheckVectorString(std::string path, std::vector<std::string> vrword)
{
	bool status = false;

	for (size_t i = 0; i < vrword.size(); i++)
	{
		if (CheckString(path, vrword[i]))
		{
			status = true;
			break;
		}
	}
	return status;
}

bool ChatLog::CheckFile(std::string path)
{
	bool status = false;

	std::ifstream fin(path.c_str());

	if (fin.is_open())
	{
		status = true;
	}
	else
	{
		status = false;
	}
	fin.close();
	return status;
}

