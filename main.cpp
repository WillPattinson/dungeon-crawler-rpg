#include <iostream>
#include "Player.h"
#include "Room.h"

int main() {
    
    Player player("Hero", 100, 10);
    Room room("A dark dungeon room with stone walls", false);

    std::cout << "Welcome " << player.name << '\n';
    std::cout << room.description << '\n';
    
    return 0;
}