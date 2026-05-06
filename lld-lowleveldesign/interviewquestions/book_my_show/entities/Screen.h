#pragma once
#include <vector>
#include <map>
#include "Seat.h"
#include "Show.h"
using namespace std;

class Screen {
private:
    int screenId;
    vector<Seat*> seats;
    map<string, vector<Show*>> showsByDate; // date string -> shows

public:
    Screen(int screenId, vector<Seat*> seats)
        : screenId(screenId), seats(move(seats)) {}

    vector<Seat*>& getSeats() { return seats; }

    void addShow(Show* show) {
        string dateKey = show->getShowDate().toString();
        showsByDate[dateKey].push_back(show);
    }

    vector<Show*> getShows(LocalDate date) {
        string dateKey = date.toString();
        auto it = showsByDate.find(dateKey);
        if (it != showsByDate.end()) {
            return it->second;
        }
        return {};
    }
};
