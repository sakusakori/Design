#pragma once
#include <map>
#include <vector>
#include <stdexcept>
#include "../entities/Booking.h"
#include "../entities/Payment.h"
#include "../entities/Show.h"
#include "../entities/User.h"
#include "../enums/PaymentStatus.h"
using namespace std;

class BookingService {
private:
    map<int, Booking*> bookings;

public:
    Booking* book(User* user, Show* show, vector<int> seats) {

        if (!show->lockSeats(seats)) {
            throw runtime_error("Seat unavailable");
        }

        //simulated payment flow here, we can invoke Pay method of Payment Controller
        Payment* payment = new Payment(SUCCESS);

        if (payment->getStatus() == SUCCESS) {
            show->confirmSeats(seats);
            Booking* booking = new Booking(user, show, seats, payment);
            bookings[booking->getBookingId()] = booking;
            return booking;
        } else {
            show->releaseSeats(seats);
            throw runtime_error("Payment failed");
        }
    }

    Booking* getBooking(int bookingId) {
        auto it = bookings.find(bookingId);
        if (it != bookings.end()) return it->second;
        return nullptr;
    }

    vector<Booking*> getBookingsForUser(User* user) {
        vector<Booking*> result;
        for (auto& pair : bookings) {
            if (pair.second->getUser() == user) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};
