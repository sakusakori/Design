#pragma once
#include "LogProcessor.h"

// Concrete handler for INFO level
class InfoLogProcessor : public LogProcessor {
public:
    InfoLogProcessor(int level) {
        this->level = level;
    }

protected:
    void write(string message) override {
        cout << "INFO: " << message << endl;
    }
};
