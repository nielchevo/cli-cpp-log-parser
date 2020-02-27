#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Logger
{
private:
    static Logger* m_instance;

    unsigned int m_interval;
    const char* m_filename;

    Logger();
    ~Logger();

public:
    static Logger* GetInstance();

    int readFile(const char* nMin, const char* nFile);
};

