#pragma once
#include <string>

class Player {
    public:
        std::string name;
        int health;
        int attackPower;

        Player(std::string name, int health, int attackPower);
};
