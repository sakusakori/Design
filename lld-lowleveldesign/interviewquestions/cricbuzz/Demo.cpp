#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "Match.h"
#include "T20Match.h"
#include "Team/Team.h"
#include "Team/Player/Person.h"
#include "Team/Player/PlayerDetails.h"
#include "Team/Player/PlayerType.h"
using namespace std;

PlayerDetails* addPlayer(string name, PlayerType playerType) {
    Person* person = new Person();
    person->name = name;
    PlayerDetails* playerDetails = new PlayerDetails(person, playerType);
    return playerDetails;
}

Team* addTeam(string name) {
    queue<PlayerDetails*> playerDetails;

    PlayerDetails* p1  = addPlayer(name + "1", ALLROUNDER);
    PlayerDetails* p2  = addPlayer(name + "2", ALLROUNDER);
    PlayerDetails* p3  = addPlayer(name + "3", ALLROUNDER);
    PlayerDetails* p4  = addPlayer(name + "4", ALLROUNDER);
    PlayerDetails* p5  = addPlayer(name + "5", ALLROUNDER);
    PlayerDetails* p6  = addPlayer(name + "6", ALLROUNDER);
    PlayerDetails* p7  = addPlayer(name + "7", ALLROUNDER);
    PlayerDetails* p8  = addPlayer(name + "8", ALLROUNDER);
    PlayerDetails* p9  = addPlayer(name + "9", ALLROUNDER);
    PlayerDetails* p10 = addPlayer(name + "10", ALLROUNDER);
    PlayerDetails* p11 = addPlayer(name + "11", ALLROUNDER);

    playerDetails.push(p1);
    playerDetails.push(p2);
    playerDetails.push(p3);
    playerDetails.push(p4);
    playerDetails.push(p5);
    playerDetails.push(p6);
    playerDetails.push(p7);
    playerDetails.push(p8);
    playerDetails.push(p9);
    playerDetails.push(p10);
    playerDetails.push(p11);

    vector<PlayerDetails*> bowlers;
    bowlers.push_back(p8);
    bowlers.push_back(p9);
    bowlers.push_back(p10);
    bowlers.push_back(p11);

    Team* team = new Team(name, playerDetails, {}, bowlers);
    return team;
}

int main() {
    srand(time(nullptr));

    Team* teamA = addTeam("India");
    Team* teamB = addTeam("SriLanka");

    T20Match matchType;
    Match match(teamA, teamB, "SMS STADIUM", &matchType);
    match.startMatch();

    return 0;
}
