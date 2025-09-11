#pragma once

#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

namespace LOGICGATES {

	int AND(int a, int b) {
		if (a > 1 || b > 1) return -1;
		if (a == 1 && b == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int OR(int a, int b) {
		if (a > 1 || b > 1) return -1;
		if (a == 1 || b == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int NOT(int a) {
		if (a > 1) return -1;
		if (a == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int NAND(int a, int b) {
		return NOT(AND(a, b));
	}

	int NOR(int a, int b) {
		return NOT(OR(a, b));
	}

	int XOR(int a, int b) {
		return AND(OR(a, b), NOT(AND(a, b)));
	}

	int XNOR(int a, int b) {
		return OR(AND(a, b), AND(NOT(a), NOT(b)));
	}

}

#endif
