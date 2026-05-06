#include <iostream>
#include "observable/IphoneProductObservable.h"
#include "observer/EmailNotificationObserver.h"
#include "observer/PushNotificationObserver.h"
using namespace std;

int main() {
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "###### E-commerce Store - Stock Availability Notification Feature Demo ######" << endl;

    // Create an iPhone product - stock available = 10 units
    IphoneProductObservable iphoneProduct("ip15", "iphone 15", 1250, 10);

    // Create observers
    PushNotificationObserver John_PUSH("John123", "JohnDeviceP1");
    PushNotificationObserver Katy_PUSH("Katy678", "KatyDeviceP2");
    EmailNotificationObserver Jane_EMAIL("Jane783", "jane783@gmail.com");
    EmailNotificationObserver George_EMAIL("George993", "george993@gmail.com");

    // Black Friday Sale - Purchase all 10 units
    iphoneProduct.purchase(10);

    // Stock unavailability leads to users subscribing for notifications
    bool success = iphoneProduct.purchase(1); // Failed purchase
    if (!success) {
        // Register observers - John, Katy, Jane, George subscribe to notifications upon stock availability
        iphoneProduct.addStockObserver(&John_PUSH);   // John
        iphoneProduct.addStockObserver(&Katy_PUSH);   // Katy
        iphoneProduct.addStockObserver(&Jane_EMAIL);   // Jane
        iphoneProduct.addStockObserver(&George_EMAIL); // George
    }

    // Restock 20 units of iPhone 15
    iphoneProduct.restock(20); // All 4 observers are notified

    // Users purchase upon receiving notifications
    iphoneProduct.purchase(1); // John purchases 1 unit
    iphoneProduct.purchase(1); // Katy purchases 1 unit

    // John & Katy unsubscribe from notifications
    iphoneProduct.removeStockObserver(&John_PUSH);
    iphoneProduct.removeStockObserver(&Katy_PUSH);

    // NYE Sale - All 18 units sold
    iphoneProduct.purchase(18);
    iphoneProduct.restock(5); // Only Jane & George are notified

    iphoneProduct.purchase(1); // Jane purchases 1 unit
    iphoneProduct.purchase(1); // George purchases 1 unit

    // Jane & George unsubscribe from notifications
    iphoneProduct.removeStockObserver(&Jane_EMAIL);
    iphoneProduct.removeStockObserver(&George_EMAIL);

    return 0;
}
