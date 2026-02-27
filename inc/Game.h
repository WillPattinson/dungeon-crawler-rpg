#pragma once
#include <vector>
#include <memory>
#include "Room.h"
#include "Player.h"


class Game {
    private:
        std::vector<std::unique_ptr<Room>> rooms;
        Player player;
        Room* currentRoom;

    public:
        Game();
        void start();
        void createRooms();
        void move(std::string direction);
        void displayCurrentRoom();
};