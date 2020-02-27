// cpp-logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger.h"


int main(int argc, const char* argv[])
{
	if (argc != 5)
	{
		std::cout << "args must be contain -t <minute> and -d <input file>";
		return 1;
	}

	Logger::GetInstance()->readFile(argv[2], argv[4]);
	
	Logger::GetInstance()->printStack();

	return 0;
}