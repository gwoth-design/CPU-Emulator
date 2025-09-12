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

    std::array<int, 2> fullAdder(int a, int b, int cin) {
        auto first = halfAdder(a, b);
        auto second = halfAdder(first[1], cin);
        int carry = LOGICGATES::OR(first[0], second[0]);
        int sum = second[1];
        return { carry, sum };
    }

    std::array<int, 3> full2BitAdder(std::array<int, 2> a, std::array<int, 2> b, int carry) {
        auto lsb = fullAdder(a[1], b[1], carry); //lsb
        auto msb = fullAdder(a[0], b[0], lsb[0]); //msb
        return { msb[0], msb[1], lsb[1] }; //carry, msb, lsb
    }

    std::array<int, 5> full4BitAdder(std::array<int, 4> a, std::array<int, 4> b, int carry) {
        auto lsbHalf = full2BitAdder({ a[2], a[3] }, { b[2], b[3] }, carry);
        auto msbHalf = full2BitAdder({ a[0], a[1] }, { b[0], b[1] }, lsbHalf[0]);
        return { msbHalf[0], msbHalf[1], msbHalf[2], lsbHalf[1], lsbHalf[2] }; //carry, bit4, bit3, bit2, bit1
    }

    std::array<int, 9> full8BitAdder(std::array<int, 8> a, std::array<int, 8> b, int carry) {
        auto lsbHalf = full4BitAdder({ a[4], a[5], a[6], a[7] }, { b[4], b[5], b[6], b[7] }, carry);
        auto msbHalf = full4BitAdder({ a[0], a[1], a[2], a[3] }, { b[0], b[1], b[2], b[3] }, lsbHalf[0]);
        return { msbHalf[0], msbHalf[1], msbHalf[2], msbHalf[3], msbHalf[4], lsbHalf[1], lsbHalf[2], lsbHalf[3], lsbHalf[4] }; //carry then msb->lsb
    }

    std::array<int, 17> full16BitAdder(std::array<int, 16> a, std::array<int, 16> b, int carry) {
        auto lsbHalf = full8BitAdder({ a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15] }, { b[8], b[9], b[10], b[11], b[12], b[13], b[14], b[15] }, carry);
        auto msbHalf = full8BitAdder({ a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7] }, { b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7] }, lsbHalf[0]);
        return { msbHalf[0], msbHalf[1], msbHalf[2], msbHalf[3], msbHalf[4], msbHalf[5], msbHalf[6], msbHalf[7], lsbHalf[1], lsbHalf[2], lsbHalf[3], lsbHalf[4], lsbHalf[5], lsbHalf[6], lsbHalf[7] }; //carry then msb->lsb
    }


    //NO JUST NO
    /*std::array<int, 33> full32BitAdder(std::array<int, 32> a, std::array<int, 32> b, int carry) {
        auto lsbHalf = full16BitAdder(
            { a[16], a[17], a[18], a[19], a[20], a[21], a[22], a[23],
              a[24], a[25], a[26], a[27], a[28], a[29], a[30], a[31] },
            { b[16], b[17], b[18], b[19], b[20], b[21], b[22], b[23],
              b[24], b[25], b[26], b[27], b[28], b[29], b[30], b[31] },
            carry
        );

        auto msbHalf = full16BitAdder(
            { a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7],
              a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15] },
            { b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7],
              b[8], b[9], b[10], b[11], b[12], b[13], b[14], b[15] },
            lsbHalf[0]
        );

        return {
            msbHalf[0], msbHalf[1], msbHalf[2], msbHalf[3], msbHalf[4], msbHalf[5], msbHalf[6], msbHalf[7],
            msbHalf[8], msbHalf[9], msbHalf[10], msbHalf[11], msbHalf[12], msbHalf[13], msbHalf[14], msbHalf[15], msbHalf[16],
            lsbHalf[1], lsbHalf[2], lsbHalf[3], lsbHalf[4], lsbHalf[5], lsbHalf[6], lsbHalf[7],
            lsbHalf[8], lsbHalf[9], lsbHalf[10], lsbHalf[11], lsbHalf[12], lsbHalf[13], lsbHalf[14], lsbHalf[15], lsbHalf[16]
        }; // carry then msb->lsb
    }*/


}

#endif
