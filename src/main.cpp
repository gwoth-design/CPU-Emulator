#include <iostream>
#include "../headers/logicGates.h"
#include "../headers/ALU.h"

void displayGates() {
    std::cout << LOGICGATES::andGates << " AND GATES\n";
    std::cout << LOGICGATES::orGates << " OR GATES\n";
    std::cout << LOGICGATES::notGates << " NOT GATES\n";
    std::cout << LOGICGATES::nandGates << " NAND GATES\n";
    std::cout << LOGICGATES::norGates << " NOR GATES\n";
    std::cout << LOGICGATES::xorGates << " XOR GATES\n";
    std::cout << LOGICGATES::xnorGates << " XNOR GATES\n";
}

int main() {
    int a = 173; // hardcoded 8-bit number (10101101)
    int b = 89;  // hardcoded 8-bit number (01011001)
    int cin = 1; // hardcoded carry-in

    std::array<int, 8> a_bits = {
        (a >> 7) & 1, (a >> 6) & 1, (a >> 5) & 1, (a >> 4) & 1,
        (a >> 3) & 1, (a >> 2) & 1, (a >> 1) & 1, (a >> 0) & 1
    };
    std::array<int, 8> b_bits = {
        (b >> 7) & 1, (b >> 6) & 1, (b >> 5) & 1, (b >> 4) & 1,
        (b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, (b >> 0) & 1
    };

    auto res = ALU::full8BitAdder(a_bits, b_bits, cin);

    std::cout << "A=";
    for (auto bit : a_bits) std::cout << bit;
    std::cout << " B=";
    for (auto bit : b_bits) std::cout << bit;
    std::cout << " Cin=" << cin << " -> CoutSum=";
    for (auto bit : res) std::cout << bit;
    std::cout << "\n";

    displayGates();

    return 0;
}
