#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::unordered_map<char, std::string> hexToBinaryMap = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};

void hexToBinary(char hex) {
    if (hexToBinaryMap.find(toupper(hex)) != hexToBinaryMap.end()) {
        std::cout << hexToBinaryMap[toupper(hex)];
    } else {
        std::cerr << "Invalid hexadecimal digit: " << hex << std::endl;
    }
}

int main() {
    std::ifstream inputFile("hex.txt"); // Assuming the input file is named "hex.txt"
    freopen("array.txt", "w", stdout);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::string hex;
    std::string binary;
    char hexChar;
    int i = 0;

    // Read characters from the file
    while (inputFile.get(hexChar)) {
        if(hexChar != EOF && hexChar != '\n' && hexChar != ' '){
            if (i == 0)
            {
                printf("{0b");
                hexToBinary(hexChar);
            }
            else if (i == 1)
            {
                hexToBinary(hexChar);
            }
            else if (i == 2)
            {
                printf(", 0b");
                hexToBinary(hexChar);
            }
            else if (i == 3)
            {
                hexToBinary(hexChar);
                printf("},\n");
                i = -1;
            }
            i++;
        }
    }

    // Close the input file
    inputFile.close();
    fclose(stdout);
    return 0;
}
