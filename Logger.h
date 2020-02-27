#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>

#define BOOST_DATE_TIME_NO_LIB
#include <boost/date_time.hpp>

struct lineContent {
    
    std::string address;
    std::string auth;
    std::string name;
    std::string dateUTC;
    std::string timezone;
    std::string http_method;
    std::string api_url;
    std::string http_ver;
    std::string http_code;
    std::string byteSize;

    std::string lineStr;
    time_t interval;
};

class Logger
{
private:
    static Logger* m_instance;

    int m_interval;
    const char* m_filename;
    std::stack<lineContent> m_lineStack;

    Logger();
    ~Logger();

    lineContent parserLine(std::string nLine);
    
    time_t parseDateTime(std::string dateTime, std::string nUTC);

public:
    static Logger* GetInstance();

    void printStack();
    int readFile(const char* nMin, const char* nFile);
};

