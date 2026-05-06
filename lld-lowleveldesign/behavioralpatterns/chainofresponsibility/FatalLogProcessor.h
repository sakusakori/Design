#pragma once
#include "LogProcessor.h"

// Concrete handler for FATAL level
class FatalLogProcessor : public LogProcessor {
public:
    FatalLogProcessor(int level) {
        this->level = level;
    }

protected:
    void write(string message) override {
        cout << "FATAL: " << message << endl;
    }
};
