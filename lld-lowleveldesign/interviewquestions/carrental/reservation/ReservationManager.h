#pragma once
#include <stdexcept>
#include "../product/VehicleInventoryManager.h"
#include "../product/DateInterval.h"
#include "Reservation.h"
#include "ReservationRepository.h"
#include "ReservationType.h"
using namespace std;

class User;

class ReservationManager {
private:
    VehicleInventoryManager* inventory;
    ReservationRepository reservationRepository;
    int reservationIdCounter = 20000;

public:
    ReservationManager(VehicleInventoryManager* inventory)
        : inventory(inventory) {
        inventory->setReservationRepository(&reservationRepository);
    }

    // ----------------- Get Reservation -----------------
    Reservation* findByID(int reservationId) {
        return reservationRepository.findById(reservationId);
    }

    // ----------------- Create Reservation -----------------
    Reservation* createReservation(int vehicleId, int userId,
                                   LocalDate from, LocalDate to,
                                   ReservationType type) {

        int reservationId = reservationIdCounter++;
        bool reserved = inventory->reserve(vehicleId, reservationId, from, to);

        if (!reserved) {
            throw runtime_error("Vehicle not available for selected dates");
        }

        Reservation* reservation = new Reservation(reservationId, vehicleId,
                                                    userId, from, to, type);
        reservationRepository.save(reservation);
        return reservation;
    }

    // ----------------- Cancel -----------------------------
    void cancelReservation(int reservationId) {
        Reservation* r = reservationRepository.findById(reservationId);
        if (r == nullptr) {
            throw runtime_error("Reservation not found");
        }

        r->setReservationStatus(CANCELLED);
        inventory->release(r->getVehicleId(), r->getReservationId());
        reservationRepository.remove(reservationId);
    }

    // ----------------- Start Trip -------------------------
    void startTrip(int reservationId) {
        Reservation* r = reservationRepository.findById(reservationId);
        if (r == nullptr) throw runtime_error("Reservation not found");
        r->setReservationStatus(IN_USE);
    }

    // ----------------- Submit Vehicle ---------------------
    void submitVehicle(int reservationId) {
        Reservation* r = reservationRepository.findById(reservationId);
        if (r == nullptr) throw runtime_error("Reservation not found");

        r->setReservationStatus(COMPLETED);
        inventory->release(r->getVehicleId(), r->getReservationId());
    }

    // ----------------- Remove reservation -----------------
    void remove(int reservationId) {
        reservationRepository.remove(reservationId);
    }
};
