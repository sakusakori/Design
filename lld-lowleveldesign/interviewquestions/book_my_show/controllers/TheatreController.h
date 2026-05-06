#pragma once
#include <vector>
#include <set>
#include "../entities/Movie.h"
#include "../entities/Show.h"
#include "../entities/Theatre.h"
#include "../enums/City.h"
#include "../service/TheatreService.h"
using namespace std;

class TheatreController {
private:
    TheatreService theatreService;

public:
    void addTheatre(Theatre* theatre) {
        theatreService.addTheatre(theatre);
    }

    set<Movie*> getMovies(City city, LocalDate date) {
        return theatreService.getMovies(city, date);
    }

    vector<Theatre*> getTheatres(City city, Movie* movie, LocalDate date) {
        return theatreService.getTheatres(city, movie, date);
    }

    vector<Show*> getShows(Movie* movie, LocalDate date, Theatre* theatre) {
        return theatreService.getShows(movie, date, theatre);
    }
};
