#pragma once
#include <stack>
#include "ICommand.h"
using namespace std;

// Invoker - with undo functionality
class RemoteController {
public:
    ICommand* command;
    stack<ICommand*> commandHistory;

    RemoteController() : command(nullptr) {}

    void setCommand(ICommand* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
        commandHistory.push(command);
    }

    void undo() {
        if (!commandHistory.empty()) {
            ICommand* lastCommand = commandHistory.top();
            commandHistory.pop();
            lastCommand->undo();
        }
    }
};
