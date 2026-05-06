#include <iostream>
#include <vector>
#include "controllers/TheatreController.h"
#include "controllers/BookingController.h"
#include "entities/Movie.h"
#include "entities/User.h"
#include "entities/Seat.h"
#include "entities/Screen.h"
#include "entities/Show.h"
#include "entities/Theatre.h"
#include "entities/Booking.h"
#include "enums/City.h"
#include "enums/SeatCategory.h"
using namespace std;

vector<Seat*> createSeats() {
    vector<Seat*> seats;
    for (int i = 1; i <= 20; i++) {
        seats.push_back(new Seat(i, SILVER));
    }
    return seats;
}

int main() {
    srand(time(nullptr));

    TheatreController theatreController;
    BookingController bookingController;

    /*
     * 1. Create Movies
     */
    Movie baahubali("BAAHUBALI");
    Movie avengers("AVENGERS");

    /*
     * 2. Create Theatre -> Screen -> Seats
     */
    vector<Seat*> inoxSeats = createSeats();
    Screen inoxScreen1(1, inoxSeats);
    Theatre inoxTheatreBangalore("INOX", BANGALORE, {&inoxScreen1});

    vector<Seat*> pvrSeats = createSeats();
    Screen pvrScreen1(1, pvrSeats);
    Theatre pvrTheatreDelhi("PVR", DELHI, {&pvrScreen1});

    theatreController.addTheatre(&inoxTheatreBangalore);
    theatreController.addTheatre(&pvrTheatreDelhi);

    /*
     * 3. Create Shows
     */
    LocalDate today(2025, 12, 5);
    LocalDate tomorrow(2025, 12, 6);

    Show inoxMorningShowToday(&baahubali, inoxScreen1.getSeats(), today, LocalTime(8, 0));
    Show inoxAfternoonShowToday(&baahubali, inoxScreen1.getSeats(), today, LocalTime(15, 0));
    Show inoxEveningShowToday(&avengers, inoxScreen1.getSeats(), today, LocalTime(18, 0));
    Show pvrMorningShowTomorrow(&baahubali, pvrScreen1.getSeats(), tomorrow, LocalTime(9, 0));

    // Attach shows to screens
    inoxScreen1.addShow(&inoxMorningShowToday);
    inoxScreen1.addShow(&inoxAfternoonShowToday);
    inoxScreen1.addShow(&inoxEveningShowToday);
    pvrScreen1.addShow(&pvrMorningShowTomorrow);

    /*
     * USER FLOW (END TO END)
     */

    // User enters system
    User user("U1", "Shrayansh");
    cout << "User logged in: Shrayansh" << endl;

    // 1. User selects city
    City selectedCity = BANGALORE;
    cout << "Selected City: " << cityName(selectedCity) << endl;

    // 2. For specific date, show movies running in city
    LocalDate selectedDate = today;
    cout << "Selected Date: " << selectedDate.toString() << endl;

    set<Movie*> movies = theatreController.getMovies(selectedCity, selectedDate);
    cout << "Movies available:" << endl;
    for (Movie* m : movies) {
        cout << " - " << m->getName() << endl;
    }

    // 3. User selects movie
    Movie* selectedMovie = *movies.begin(); // selecting first movie
    cout << "Selected Movie: " << selectedMovie->getName() << endl;

    // 4. Show theatres and show times in city
    vector<Theatre*> theatres = theatreController.getTheatres(selectedCity, selectedMovie, selectedDate);
    cout << "Theatres available:" << endl;
    for (Theatre* t : theatres) {
        cout << " - " << t->getName() << endl;
    }

    // 6. User selects theatre
    Theatre* selectedTheatre = theatres[0];
    cout << "Selected Theatre: " << selectedTheatre->getName() << endl;

    // 7. Show running shows for movie + date + theatre
    vector<Show*> shows = theatreController.getShows(selectedMovie, selectedDate, selectedTheatre);
    cout << "Shows available:" << endl;
    for (Show* s : shows) {
        cout << " - " << s->getStartTime().toString() << endl;
    }

    // 8. User selects show
    Show* selectedShow = shows[0];
    cout << "Selected Show Time: " << selectedShow->getStartTime().toString() << endl;

    // 9. User selects seats
    vector<int> selectedSeats = {1, 2, 3};
    cout << "Selected Seats: 1, 2, 3" << endl;

    // 10. Booking + Payment
    Booking* booking = bookingController.createBooking(&user, selectedShow, selectedSeats);

    cout << "BOOKING SUCCESSFUL" << endl;
    cout << "Booking ID: " << booking->getBookingId() << endl;

    // Cleanup seats
    for (Seat* s : inoxSeats) delete s;
    for (Seat* s : pvrSeats) delete s;

    return 0;
}
