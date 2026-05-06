#pragma once
#include <string>
using namespace std;

// Observer interface for stock availability notifications
class StockNotificationObserver {
public:
    virtual ~StockNotificationObserver() = default;

    virtual void update() = 0;

    virtual string getNotificationMethod() = 0;

    virtual string getUserId() = 0;
};
