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
	
	m_interval = (int)std::atoi(nMin);

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

#ifdef DEBUG
		std::cout << parseLine.c_str() << std::endl;
#endif
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

	data.interval = parseDateTime(data.dateUTC, data.timezone);
	data.lineStr = nLine;
	return data;
}

time_t Logger::parseDateTime(std::string dateTime, std::string nUTC)
{
	struct tm tm;
	std::istringstream s(dateTime);
	
	s >> std::get_time(&tm, "[%d/%b/%Y:%H:%M:%S");
	time_t time = mktime(&tm);

#ifdef DEBUG
	std::cout << time << std::endl;
#endif

	return time;
}

void Logger::printStack()
{
	time_t start = m_lineStack.top().interval;

	std::cout << "begin :" << start << std::endl;
	std::cout << "inteval -t: " << m_interval << std::endl;
	
	std::chrono::system_clock::time_point x = std::chrono::system_clock::from_time_t(start) - std::chrono::minutes(m_interval);
	time_t stop = std::chrono::system_clock::to_time_t(x);
	//std::cout << "end at : " << std::put_time(std::localtime_s(&stop), L"%A") << std::endl;

	bool stops = false;
	while (!stops)
	{
		if (m_lineStack.empty()) {
			stops = true;
			break;
		}

		lineContent w = m_lineStack.top();

		if (w.interval <= stop) {
			stops = true;
			break;
		}
		
		std::cout << w.lineStr.c_str() << std::endl;

		m_lineStack.pop();
	}
}

