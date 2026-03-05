#include "Game.h"
#include <iostream>
#include <limits>


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

        std::cout << "What do you do?\n";
        std::getline(std::cin, input);
        

        if(input == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else {
            move(input);
        }

        if(currentRoom->hasEnemy) {
            battle();
        }
    }
}

void Game::createRooms() {
    rooms.push_back(std::make_unique<Room>("A dark dungeon room with stone walls", false));
    rooms.push_back(std::make_unique<Room>("A dimly lit kitchen", false));
    rooms.push_back(std::make_unique<Room>("A long dark hallway", false));
    rooms.push_back(std::make_unique<Room>("A large throne room", true));
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

void Game::battle() {
    Enemy enemy("Orc", 50, 50);
    std::cout << "An enemy " << enemy.name << " approaches!\n";
    int playerMove = 0;
    while(player.health > 0 && enemy.health > 0 && playerMove != 2) {
        //Player turn
       std::cout << "What do you do:\n"
                 << "1) Attack\n"
                 << "2) Flee\n";
        std::cin >> playerMove;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(playerMove) {
            case 1:
                enemy.health -= player.attackPower;
                std::cout << "You attack the enemy and deal " << player.attackPower << " damage!\n"
                          << "The " << enemy.name << " has " << std::max(enemy.health, 0) << " HP remaining\n";
                if(enemy.health <= 0) {
                std::cout << "The " << enemy.name << " is defeated!\n";
                currentRoom->hasEnemy = false;
                }
                break;
            case 2:
                currentRoom->hasEnemy = false;
                std::cout << "You flee succesfully!\n";
                break;
            default:
                std::cout << "Not a valid action\n";
                continue;
        }

        //Enemy turn
        if(enemy.health > 0 && playerMove != 2) {
            player.health -= enemy.attackPower;
            std::cout << "The " << enemy.name << " attacks you for " << enemy.attackPower << " damage!\n"
                    << "You have " << std::max(player.health, 0) << " HP remaining\n";
            if(player.health <= 0) {
                std::cout << "YOU DIED!\n";
            }
        }
    }
}
