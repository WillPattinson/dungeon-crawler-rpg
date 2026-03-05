cmake_minimum_required(VERSION 3.10)
project(DungeonCrawler)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc/)

add_executable(DungeonCrawler
    main.cpp
    src/Player.cpp
    src/Room.cpp
    src/Game.cpp
    src/Enemy.cpp
)