#pragma once

// Step 1: Component interface
class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;

    virtual void printContents() = 0;
};
