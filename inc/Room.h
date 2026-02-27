#pragma once
#include <string>

class Room {
    public:
        std::string description;
        bool hasEnemy;
        Room* north = nullptr;
        Room* east = nullptr;
        Room* south = nullptr;
        Room* west = nullptr;

        Room(std::string description, bool hasEnemy);
};