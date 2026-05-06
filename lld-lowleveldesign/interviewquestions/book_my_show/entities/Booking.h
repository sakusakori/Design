#pragma once
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Show.h"
#include "Payment.h"
using namespace std;

class Booking {
private:
    int bookingId;
    User* user;
    Show* show;
    vector<int> seats;
    Payment* payment;

public:
    Booking(User* user, Show* show, vector<int> seats, Payment* payment)
        : bookingId(rand()), user(user), show(show),
          seats(move(seats)), payment(payment) {}

    int getBookingId() { return bookingId; }
    User* getUser() { return user; }
    Payment* getPayment() { return payment; }
};
