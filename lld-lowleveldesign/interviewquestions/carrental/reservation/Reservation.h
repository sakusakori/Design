#pragma once
#include "../product/DateInterval.h"
#include "ReservationType.h"
#include "ReservationStatus.h"

class Reservation {
private:
    int reservationId;
    int vehicleId;
    int userId;
    LocalDate dateBookedFrom;
    LocalDate dateBookedTo;
    ReservationType reservationType;
    ReservationStatus reservationStatus;

public:
    Reservation(int reservationId, int vehicleId, int userId,
                LocalDate dateBookedFrom, LocalDate dateBookedTo,
                ReservationType reservationType)
        : reservationId(reservationId), vehicleId(vehicleId), userId(userId),
          dateBookedFrom(dateBookedFrom), dateBookedTo(dateBookedTo),
          reservationType(reservationType), reservationStatus(SCHEDULED) {}

    // Getters
    int getReservationId() { return reservationId; }
    int getVehicleId() { return vehicleId; }
    int getUserId() { return userId; }
    LocalDate getDateBookedFrom() { return dateBookedFrom; }
    LocalDate getDateBookedTo() { return dateBookedTo; }
    ReservationType getReservationType() { return reservationType; }
    ReservationStatus getReservationStatus() { return reservationStatus; }

    // Setter
    void setReservationStatus(ReservationStatus status) { reservationStatus = status; }
};
