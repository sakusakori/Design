#pragma once
#include <string>
#include <stdexcept>
using namespace std;

// Simple date representation (year, month, day) to keep it easy
struct LocalDate {
    int year, month, day;

    LocalDate() : year(0), month(0), day(0) {}
    LocalDate(int year, int month, int day) : year(year), month(month), day(day) {}

    bool isBefore(const LocalDate& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool isAfter(const LocalDate& other) const {
        return other.isBefore(*this);
    }

    // Returns number of days between two dates (approximate, good enough for demo)
    long daysBetween(const LocalDate& other) const {
        long d1 = year * 365L + month * 30L + day;
        long d2 = other.year * 365L + other.month * 30L + other.day;
        long diff = d2 - d1;
        return diff >= 0 ? diff : -diff;
    }

    string toString() const {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

class DateInterval {
private:
    LocalDate from;
    LocalDate to;

public:
    DateInterval(LocalDate from, LocalDate to) : from(from), to(to) {
        if (to.isBefore(from)) {
            throw invalid_argument("End date cannot be before start date");
        }
    }

    LocalDate getFrom() { return from; }
    LocalDate getTo() { return to; }

    bool overlaps(DateInterval& other) {
        return !(this->to.isBefore(other.from) || this->from.isAfter(other.to));
    }
};
