#pragma once
#include <vector>
#include <map>
#include <mutex>
#include <algorithm>
#include "Movie.h"
#include "Seat.h"
#include "../enums/SeatStatus.h"
using namespace std;

// Simple time representation
struct LocalTime {
    int hour, minute;
    LocalTime() : hour(0), minute(0) {}
    LocalTime(int h, int m) : hour(h), minute(m) {}
    string toString() {
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }
};

// Simple date representation
struct LocalDate {
    int year, month, day;
    LocalDate() : year(0), month(0), day(0) {}
    LocalDate(int y, int m, int d) : year(y), month(m), day(d) {}

    bool operator<(const LocalDate& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator==(const LocalDate& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    string toString() {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }

    LocalDate plusDays(int d) {
        return LocalDate(year, month, day + d); // simplified
    }
};

class Screen; // forward declaration

class Show {
private:
    Movie* movie;
    LocalDate showDate;
    LocalTime startTime;

    map<int, SeatStatus> seatStatusMap;
    map<int, mutex*> seatLocks;

public:
    Show(Movie* movie, vector<Seat*>& seats, LocalDate date, LocalTime time)
        : movie(movie), showDate(date), startTime(time) {

        for (Seat* seat : seats) {
            seatStatusMap[seat->getSeatId()] = AVAILABLE;
            seatLocks[seat->getSeatId()] = new mutex();
        }
    }

    ~Show() {
        for (auto& pair : seatLocks) {
            delete pair.second;
        }
    }

    Movie* getMovie() { return movie; }
    LocalDate getShowDate() { return showDate; }
    LocalTime getStartTime() { return startTime; }

    bool lockSeats(vector<int>& seatIds) {
        vector<int> sorted(seatIds);

        //sorting i am doing to avoid deadlock scenario
        sort(sorted.begin(), sorted.end());

        vector<mutex*> acquiredLocks;

        // Phase 1: acquire all locks
        for (int seatId : sorted) {
            mutex* lk = seatLocks[seatId];
            lk->lock();
            acquiredLocks.push_back(lk);
        }

        bool success = true;

        // Phase 2: validate availability
        for (int seatId : sorted) {
            if (seatStatusMap[seatId] != AVAILABLE) {
                success = false;
                break;
            }
        }

        // Phase 3: mark LOCKED (only if all available)
        if (success) {
            for (int seatId : sorted) {
                seatStatusMap[seatId] = LOCKED;
            }
        }

        // Phase 4: release locks
        for (mutex* lk : acquiredLocks) {
            lk->unlock();
        }

        return success;
    }

    void confirmSeats(vector<int>& seatIds) {
        for (int seatId : seatIds) {
            seatStatusMap[seatId] = BOOKED;
        }
    }

    void releaseSeats(vector<int>& seatIds) {
        for (int seatId : seatIds) {
            seatStatusMap[seatId] = AVAILABLE;
        }
    }
};
