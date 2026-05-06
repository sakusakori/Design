#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract Logger class - defines the chain structure
class LogProcessor {
public:
    static const int DEBUG = 1;
    static const int INFO = 2;
    static const int ERROR = 3;
    static const int FATAL = 4;

    int level;
    LogProcessor* nextLoggerProcessor = nullptr;

    virtual ~LogProcessor() = default;

    void setNextLogger(LogProcessor* nextLogger) {
        this->nextLoggerProcessor = nextLogger;
    }

    void logMessage(int level, string message) {
        if (this->level == level) {
            write(message);
            return;
        }

        // Pass to next handler in chain if exists
        if (this->nextLoggerProcessor != nullptr) {
            this->nextLoggerProcessor->logMessage(level, message);
        }
    }

protected:
    virtual void write(string message) = 0;
};
