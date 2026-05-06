#pragma once
#include "LogProcessor.h"

// Concrete handler for ERROR level
class ErrorLogProcessor : public LogProcessor {
public:
    ErrorLogProcessor(int level) {
        this->level = level;
    }

protected:
    void write(string message) override {
        cout << "ERROR: " << message << endl;
    }
};
