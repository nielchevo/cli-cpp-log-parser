#include "Logger.h"


// init singleton
Logger* Logger::m_instance = NULL;

Logger* Logger::GetInstance()
{
	if (!m_instance) {
		m_instance = new Logger();
	}
	return m_instance;
}

Logger::Logger() {};

Logger::~Logger() {};


int Logger::readFile(const char* nMin, const char* nFilename)
{
	std::ifstream tInputFile;

	tInputFile.open(nFilename);

	if (!tInputFile) {
		std::cout << "failed to read file input ";
		return 0;
	}

	tInputFile.close();

	return 1;
}

