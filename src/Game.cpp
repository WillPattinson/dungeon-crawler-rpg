#include "Game.h"
#include <iostream>


Game::Game() : currentRoom(nullptr), player("", 100, 10) {}

void Game::start() {
    createRooms();
    currentRoom = rooms[0].get();

    std::cout << "********** DUNGEON CRAWLER **********\n";

    std::string playerName;

    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    player.name = playerName;

    std::cout << "Welcome " << player.name << " to the Dungeon Crawler!\n";
    std::cout << "Commands: north, south, east, west, quit\n";

    std::string input;
    while(true) {
        displayCurrentRoom();

        std::cout << "What do you do? ";
        std::getline(std::cin, input);

        if(input == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else {
            move(input);
        }
    }
}

void Game::createRooms() {
    rooms.push_back(std::make_unique<Room>("A dark dungeon room with stone walls", false));
    rooms.push_back(std::make_unique<Room>("A dimly lit kitchen", false));
    rooms.push_back(std::make_unique<Room>("A long dark hallway", false));
    rooms.push_back(std::make_unique<Room>("A large throne room", false));
    rooms.push_back(std::make_unique<Room>("A bottomless pit lies before you", false));

    rooms[0]->north = rooms[1].get();
    rooms[1]->south = rooms[0].get();

    rooms[1]->west = rooms[2].get();
    rooms[2]->east = rooms[1].get();

    rooms[2]->north = rooms[3].get();
    rooms[3]->south = rooms[2].get();

    rooms[0]->east = rooms[4].get();
    rooms[4]->west = rooms[0].get();
}

void Game::move(std::string direction) {
    if(direction == "north" && currentRoom->north != nullptr) {
        currentRoom = currentRoom->north;
    }
    else if(direction == "east" && currentRoom->east != nullptr) {
        currentRoom = currentRoom->east;
    }
    else if(direction == "south" && currentRoom->south != nullptr) {
        currentRoom = currentRoom->south;
    }
    else if(direction == "west" && currentRoom->west != nullptr) {
        currentRoom = currentRoom->west;
    }
    else {
        std::cout << "You cannot go that way\n";
    }
}

void Game::displayCurrentRoom() {
    std::cout << currentRoom->description << "\n";
}
