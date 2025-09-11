#pragma once

#ifndef ALU_H
#define ALU_H

#include <array>
#include "logicGates.h"

namespace ALU {

	std::array<int, 2> halfAdder(int a, int b) {
		int sum = LOGICGATES::XOR(a, b);
		int carry = LOGICGATES::AND(a, b);
		return { carry, sum };
	}

}

#endif
