#include <iostream>
#include "Player.h"

Player::Player(std::string name, int health, int attackPower) 
    : name(name), 
      health(health),
      attackPower(attackPower) {}

