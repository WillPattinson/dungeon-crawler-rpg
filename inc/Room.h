#pragma once
#include <string>

class Room {
    public:
        std::string description;
        bool hasEnemy;

        Room(std::string description, bool hasEnemy);
};