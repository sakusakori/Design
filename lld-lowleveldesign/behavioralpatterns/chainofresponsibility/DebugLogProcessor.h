#pragma once
#include "LogProcessor.h"

// Concrete handler for DEBUG level
class DebugLogProcessor : public LogProcessor {
public:
    DebugLogProcessor(int level) {
        this->level = level;
    }

protected:
    void write(string message) override {
        cout << "DEBUG: " << message << endl;
    }
};
