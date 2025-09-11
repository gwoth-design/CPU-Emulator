#include <iostream>
#include "../headers/logicGates.h"
#include "../headers/ALU.h"

int main() {
	std::array<int, 2> res = ALU::halfAdder(0, 0);
	std::cout << res[0] << " " << res[1] << "\n";

	res = ALU::halfAdder(1, 0);
	std::cout << res[0] << " " << res[1] << "\n";

	res = ALU::halfAdder(1, 1);
	std::cout << res[0] << " " << res[1] << "\n";

	return 0;
}
