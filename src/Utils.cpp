#include "Utils.h"
#include <algorithm>
#include <limits>
#include <iostream>

void printDivider() {
    std::cout << "\n************************************\n\n";
}

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), std::tolower);
    return str;
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}