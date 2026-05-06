#pragma once

class StockNotificationObserver;

// Observable interface
class StockAvailabilityObservable {
public:
    virtual ~StockAvailabilityObservable() = default;

    virtual void addStockObserver(StockNotificationObserver* observer) = 0;

    virtual void removeStockObserver(StockNotificationObserver* observer) = 0;

    virtual void notifyStockObservers() = 0;

    virtual bool purchase(int quantity) = 0;

    virtual void restock(int quantity) = 0;
};
