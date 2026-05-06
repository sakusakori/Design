#pragma once
#include <vector>
#include <map>
#include <mutex>
#include <algorithm>
#include "Vehicle.h"
#include "DateInterval.h"
#include "../reservation/Reservation.h"
#include "../reservation/ReservationRepository.h"
using namespace std;

class VehicleInventoryManager {
private:
    // vehicleId -> Vehicle*
    map<int, Vehicle*> vehicles;

    // vehicleId -> list of reservation IDs (metadata index)
    map<int, vector<int>> vehicleBookingIds;

    // per-vehicle lock
    map<int, mutex*> vehicleLocks;

    ReservationRepository* reservationRepository = nullptr;

    mutex& lockForVehicle(int vehicleId) {
        if (vehicleLocks.find(vehicleId) == vehicleLocks.end()) {
            vehicleLocks[vehicleId] = new mutex();
        }
        return *vehicleLocks[vehicleId];
    }

public:
    ~VehicleInventoryManager() {
        for (auto& pair : vehicleLocks) {
            delete pair.second;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles[vehicle->getVehicleID()] = vehicle;
    }

    Vehicle* getVehicle(int vehicleId) {
        auto it = vehicles.find(vehicleId);
        if (it != vehicles.end()) return it->second;
        return nullptr;
    }

    void setReservationRepository(ReservationRepository* repo) {
        reservationRepository = repo;
    }

    // ---------------- Availability Check ----------------

    bool isAvailable(int vehicleId, LocalDate from, LocalDate to) {
        auto it = vehicles.find(vehicleId);
        if (it == vehicles.end()) return false;

        Vehicle* vehicle = it->second;
        if (vehicle->getVehicleStatus() == MAINTENANCE) return false;

        DateInterval requested(from, to);

        auto bookIt = vehicleBookingIds.find(vehicleId);
        if (bookIt == vehicleBookingIds.end() || bookIt->second.empty()) {
            return true;
        }

        for (int reservationID : bookIt->second) {
            Reservation* reservation = reservationRepository->findById(reservationID);
            if (reservation == nullptr) continue;
            LocalDate bookedFrom = reservation->getDateBookedFrom();
            LocalDate bookedTill = reservation->getDateBookedTo();
            DateInterval bookedInterval(bookedFrom, bookedTill);
            if (bookedInterval.overlaps(requested)) {
                return false;
            }
        }

        return true;
    }

    // ---------------- Atomic Booking ----------------

    bool reserve(int vehicleId, int reservationId, LocalDate from, LocalDate to) {
        lock_guard<mutex> guard(lockForVehicle(vehicleId));

        if (!isAvailable(vehicleId, from, to)) {
            return false;
        }

        vehicleBookingIds[vehicleId].push_back(reservationId);
        vehicles[vehicleId]->setStatus(BOOKED);

        return true;
    }

    // --------------- Atomic Release -----------------

    void release(int vehicleId, int reservationId) {
        lock_guard<mutex> guard(lockForVehicle(vehicleId));

        // remove reservation Id
        auto& ids = vehicleBookingIds[vehicleId];
        auto it = find(ids.begin(), ids.end(), reservationId);
        if (it != ids.end()) {
            ids.erase(it);
        }

        // if no more bookings -> available
        if (ids.empty()) {
            vehicles[vehicleId]->setStatus(AVAILABLE);
        }
    }

    // --------------- Search --------------------------

    vector<Vehicle*> getAvailableVehicles(VehicleType type, LocalDate from, LocalDate to) {
        vector<Vehicle*> result;
        for (auto& pair : vehicles) {
            Vehicle* v = pair.second;
            if (v->getVehicleType() == type && isAvailable(v->getVehicleID(), from, to)) {
                result.push_back(v);
            }
        }
        return result;
    }
};
