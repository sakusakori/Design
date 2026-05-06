#pragma once
#include <vector>
#include <map>
#include <set>
#include "../entities/Movie.h"
#include "../entities/Screen.h"
#include "../entities/Show.h"
#include "../entities/Theatre.h"
#include "../enums/City.h"
using namespace std;

class TheatreService {
private:
    map<City, vector<Theatre*>> cityTheatres;

public:
    void addTheatre(Theatre* theatre) {
        cityTheatres[theatre->getCity()].push_back(theatre);
    }

    set<Movie*> getMovies(City city, LocalDate date) {
        set<Movie*> movies;
        auto it = cityTheatres.find(city);
        if (it == cityTheatres.end()) return movies;

        for (Theatre* theatre : it->second) {
            for (Screen* screen : theatre->getScreens()) {
                for (Show* show : screen->getShows(date)) {
                    movies.insert(show->getMovie());
                }
            }
        }
        return movies;
    }

    vector<Theatre*> getTheatres(City city, Movie* movie, LocalDate date) {
        vector<Theatre*> result;
        auto it = cityTheatres.find(city);
        if (it == cityTheatres.end()) return result;

        for (Theatre* theatre : it->second) {
            for (Screen* screen : theatre->getScreens()) {
                for (Show* show : screen->getShows(date)) {
                    if (show->getMovie() == movie) {
                        result.push_back(theatre);
                        goto nextTheatre; // match found, skip to next theatre
                    }
                }
            }
            nextTheatre:;
        }
        return result;
    }

    vector<Show*> getShows(Movie* movie, LocalDate date, Theatre* theatre) {
        vector<Show*> result;

        for (Screen* screen : theatre->getScreens()) {
            for (Show* show : screen->getShows(date)) {
                if (show->getMovie() == movie) {
                    result.push_back(show);
                }
            }
        }
        return result;
    }
};
