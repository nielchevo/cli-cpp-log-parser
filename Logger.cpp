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
	
	std::string parseLine;

	while (!tInputFile.eof())
	{
		std::getline(tInputFile, parseLine);

		m_lineStack.push(parserLine(parseLine));

		std::cout << parseLine.c_str() << std::endl;
	}

	tInputFile.close();

	return 1;
}


lineContent Logger::parserLine(std::string nLine)
{
	lineContent data;
	std::stringstream s(nLine);

	s >> data.address;
	s >> data.auth;
	s >> data.name;
	s >> data.dateUTC;
	s >> data.timezone;
	s >> data.http_method;
	s >> data.api_url;
	s >> data.http_ver;
	s >> data.http_code;
	s >> data.byteSize;

	return data;
}

void Logger::printStack()
{
	while (!m_lineStack.empty())
	{
		lineContent w = m_lineStack.top();

		std::cout << w.dateUTC << std::endl;

		m_lineStack.pop();
	}
}

