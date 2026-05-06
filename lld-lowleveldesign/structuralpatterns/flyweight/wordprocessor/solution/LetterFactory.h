#pragma once
#include <map>
#include "ILetter.h"
#include "DocumentCharacter.h"
using namespace std;

// Flyweight Factory (Class) - creates and manages flyweight objects.
class LetterFactory {
private:
    static map<char, ILetter*>& getCache() {
        static map<char, ILetter*> characterCache;
        return characterCache;
    }

public:
    static ILetter* crateLetter(char characterValue) {
        auto& cache = getCache();
        if (cache.find(characterValue) != cache.end()) {
            // if exists, return the cached character object.
            return cache[characterValue];
        } else {
            // if not exists, create the character object and cache it.
            DocumentCharacter* characterObj = new DocumentCharacter(characterValue, "Arial", 10);
            // add to cache
            cache[characterValue] = characterObj;
            return characterObj;
        }
    }

    static int getTotalCharacters() {
        return getCache().size();
    }
};
