#pragma once
#include <map>
#include "Reservation.h"
using namespace std;

class ReservationRepository {
private:
    // reservationId -> Reservation*
    map<int, Reservation*> reservations;

public:
    // Save or update reservation
    void save(Reservation* reservation) {
        reservations[reservation->getReservationId()] = reservation;
    }

    // Lookup reservation by ID
    Reservation* findById(int reservationId) {
        auto it = reservations.find(reservationId);
        if (it != reservations.end()) return it->second;
        return nullptr;
    }

    // Delete reservation from repository
    void remove(int reservationId) {
        reservations.erase(reservationId);
    }

    // Return all reservations
    map<int, Reservation*>& getAll() {
        return reservations;
    }
};
