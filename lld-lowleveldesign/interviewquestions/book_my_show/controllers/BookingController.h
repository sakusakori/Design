#pragma once
#include <vector>
#include "../entities/Booking.h"
#include "../entities/Show.h"
#include "../entities/User.h"
#include "../service/BookingService.h"
using namespace std;

class BookingController {
private:
    BookingService bookingService;

public:
    Booking* createBooking(User* user, Show* show, vector<int> seats) {
        return bookingService.book(user, show, seats);
    }

    Booking* getBooking(int bookingId) {
        return bookingService.getBooking(bookingId);
    }

    vector<Booking*> getBookingsForUser(User* user) {
        return bookingService.getBookingsForUser(user);
    }
};
