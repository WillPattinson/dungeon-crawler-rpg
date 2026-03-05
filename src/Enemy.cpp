#include <iostream>
#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int attackPower) 
    : name(name), 
      health(health),
      attackPower(attackPower) {}