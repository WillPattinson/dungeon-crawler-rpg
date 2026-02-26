#include <iostream>

class Player {
    public:
        std::string name;
        int health;
        int attackPower;

        Player(std::string name, int health, int attackPower) : name(name), health(health), attackPower(attackPower) {}
};

class Room {
    public:
        std::string description;
        bool hasEnemy;

        Room(std::string description, bool hasEnemy) : description(description), hasEnemy(hasEnemy) {}
};

int main() {
    
    Player player("Hero", 100, 10);
    Room room("A dark dungeon room with stone walls", false);

    std::cout << "Welcome " << player.name << '\n';
    std::cout << room.description << '\n';
    
    return 0;
}