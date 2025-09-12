#pragma once

#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

namespace LOGICGATES {
	int andGates = 0;
	int orGates = 0;
	int notGates = 0;
	int nandGates = 0;
	int norGates = 0;
	int xnorGates = 0;
	int xorGates = 0;

	int AND(int a, int b) {

		//std::cout << "AND GATE\n";
		andGates++;

		if (a > 1 || b > 1) return -1;
		if (a == 1 && b == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int OR(int a, int b) {

		//std::cout << "OR GATE\n";
		orGates++;

		if (a > 1 || b > 1) return -1;
		if (a == 1 || b == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int NOT(int a) {

		//std::cout << "NOT GATE\n";
		notGates++;

		if (a > 1) return -1;
		if (a == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int NAND(int a, int b) {

		//std::cout << "NAND GATE\n";
		nandGates++;

		return NOT(AND(a, b));
	}

	int NOR(int a, int b) {

		//std::cout << "NOR GATE\n";
		norGates++;

		return NOT(OR(a, b));
	}

	int XOR(int a, int b) {

		//std::cout << "XOR GATE\n";
		xorGates++;

		return AND(OR(a, b), NOT(AND(a, b)));
	}

	int XNOR(int a, int b) {

		//std::cout << "XNOR GATE\n";
		xnorGates++;

		return OR(AND(a, b), AND(NOT(a), NOT(b)));
	}

}

#endif
