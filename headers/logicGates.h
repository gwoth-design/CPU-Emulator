#pragma once

#ifndef LOGIC_GATES
#define LOGIC_GATES
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
		if (a == 1 || b == 1){
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

}
#endif