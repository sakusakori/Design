#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include "IRobot.h"
#include "HumanoidRobot.h"
#include "RoboticDog.h"
#include "Sprites.h"
using namespace std;

// Flyweight Factory (Class) - creates and manages flyweight objects
class RoboticFactory {
private:
    static map<string, IRobot*>& getCache() {
        static map<string, IRobot*> roboticObjectCache;
        return roboticObjectCache;
    }

public:
    static IRobot* createRobot(string robotType) {
        auto& cache = getCache();
        if (cache.find(robotType) != cache.end()) {
            // if exists, return the cached object.
            return cache[robotType];
        } else {
            // if not exists, create the object and cache it.
            if (robotType == "HUMANOID") {
                Sprites* humanoidSprite = new Sprites();
                IRobot* humanoidObject = new HumanoidRobot(robotType, humanoidSprite);
                // add to cache
                cache[robotType] = humanoidObject;
                return humanoidObject;
            } else if (robotType == "ROBOTIC_DOG") {
                Sprites* roboticDogSprite = new Sprites();
                IRobot* roboticDogObject = new RoboticDog(robotType, roboticDogSprite);
                // add to cache
                cache[robotType] = roboticDogObject;
                return roboticDogObject;
            }
        }
        throw invalid_argument("Invalid robot type: " + robotType);
    }

    static int getTotalRobots() {
        return getCache().size();
    }
};
