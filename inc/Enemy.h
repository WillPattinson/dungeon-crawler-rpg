#pragma once
#include <string>

class Enemy {
    public:
        std::string name;
        int health;
        int attackPower;

        Enemy(std::string name, int health, int attackPower);
};