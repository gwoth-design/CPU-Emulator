#include <iostream>
#include "../headers/logicGates.h"
#include "../headers/ALU.h"

#include <vector>

int main() {
    std::cout << "Testing 8-Bit Subtractor\n";
    std::cout << "M7M6M5M4M3M2M1M0 S7S6S5S4S3S2S1S0 | D7D6D5D4D3D2D1D0 Borrow | Decimal Result\n";
    std::cout << "----------------------------------------------------------------------------\n";

    std::array<int, 8> a8 = { 0,0,0,1,0,1,0,1 }; // 21
    std::array<int, 8> b8 = { 0,0,0,0,1,0,1,0 }; // 10
    auto result8 = ALU::Subtractor::full8BitSubtractor(a8, b8, 0);
    for (int i = 0; i < 8; ++i) std::cout << a8[i];
    std::cout << " ";
    for (int i = 0; i < 8; ++i) std::cout << b8[i];
    std::cout << " | ";
    for (int i = 0; i < 8; ++i) std::cout << result8[i];
    std::cout << " " << result8[8] << " | ";
    int dec8 = 0;
    for (int i = 0; i < 8; ++i) dec8 += result8[i] * (1 << (7 - i));
    if (result8[8] == 1) dec8 = -(256 - dec8);
    std::cout << "21 - 10 = 11 (" << dec8 << ")\n\n";

    std::cout << "Testing 16-Bit Subtractor\n";
    std::cout << "M15...M0 S15...S0 | D15...D0 Borrow | Decimal Result\n";
    std::cout << "----------------------------------------------------\n";

    std::array<int, 16> a16 = { 0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1 }; // 21
    std::array<int, 16> b16 = { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0 }; // 10
    auto result16 = ALU::Subtractor::full16BitSubtractor(a16, b16, 0);
    for (int i = 0; i < 16; ++i) std::cout << a16[i];
    std::cout << " ";
    for (int i = 0; i < 16; ++i) std::cout << b16[i];
    std::cout << " | ";
    for (int i = 0; i < 16; ++i) std::cout << result16[i];
    std::cout << " " << result16[16] << " | ";
    int dec16 = 0;
    for (int i = 0; i < 16; ++i) dec16 += result16[i] * (1 << (15 - i));
    if (result16[16] == 1) dec16 = -(65536 - dec16);
    std::cout << "21 - 10 = 11 (" << dec16 << ")\n\n";

    std::cout << "Testing 32-Bit Subtractor\n";
    std::cout << "M31...M0 S31...S0 | D31...D0 Borrow | Decimal Result\n";
    std::cout << "----------------------------------------------------\n";

    std::array<int, 32> a32 = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1 }; // 21
    std::array<int, 32> b32 = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0 }; // 10
    auto result32 = ALU::Subtractor::full32BitSubtractor(a32, b32, 0);
    for (int i = 0; i < 32; ++i) std::cout << a32[i];
    std::cout << " ";
    for (int i = 0; i < 32; ++i) std::cout << b32[i];
    std::cout << " | ";
    for (int i = 0; i < 32; ++i) std::cout << result32[i];
    std::cout << " " << result32[32] << " | ";
    int dec32 = 0;
    for (int i = 0; i < 32; ++i) dec32 += result32[i] * (1 << (31 - i));
    if (result32[32] == 1) dec32 = -(4294967296 - dec32);
    std::cout << "21 - 10 = 11 (" << dec32 << ")\n";

    return 0;
}