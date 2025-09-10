#include <iostream>
#include "../headers/logicGates.h"

int main() {
	std::cout << LOGICGATES::AND(0, 1) << "\n";
	std::cout << LOGICGATES::OR(0, 0) << "\n";
	std::cout << LOGICGATES::NOT(1) << "\n";

	return 0;
}