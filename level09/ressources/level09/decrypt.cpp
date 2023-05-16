#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("token");

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        for (size_t i = 0; i < line.length(); i++) {
            char character = line[i];
            int asciiValue = static_cast<int>(character);
            int result = asciiValue - static_cast<int>(i);
            std::cout << static_cast<char>(result);
        }
        std::cout << std::endl;
    }

    file.close();

    return 0;
}