#include "main.h"



int main()
{
	std::string port;
	std::cout << "Port?" << std::endl;
	std::cin >> port;

	arduino ard(port);
	ChatLog log;

	std::string path = "D:\\aion\\chat.log";

	while (true)
	{
		if (log.CheckFile(path))
		{
			if (log.CheckVectorString(path, { "sleep", "tatatata" }))
			{
				ard.sendkey('F');
				remove(path.c_str());
			}
		}
		Sleep(15);
	}
	std::cin.get();
}