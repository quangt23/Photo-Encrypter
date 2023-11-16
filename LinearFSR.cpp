// Copyright 2023 Quang Tran
#include <iostream>
#include <string>
#include <bitset>
#include "LinearFSR.hpp"

LinearFSR::LinearFSR(std::string seed) {
    // Throw exception if passes kBit_Size
    if (seed.size() != kBit_Size) {
        throw std::invalid_argument("Not correct size.");
    }
    // Initialize bit_string
    std::bitset<kBit_Size> bits(seed);
    bit_string = bits;
}

int LinearFSR::step() {
    bool XORoperation = bit_string[15] ^ bit_string[13] ^
        bit_string[12] ^ bit_string[10];
    // Shift bits left by 1
    for (int i = 15; i >= 1; i--) {
        bit_string[i] = bit_string[i-1];
    }
    // Add vacated bit to front
    bit_string[0] = XORoperation;
    return XORoperation;
}

int LinearFSR::generate(int k) {
    int bit_integer = 0;
    for (int i = 0; i < k; i ++) {
        bit_integer *= 2;
        bit_integer += step();
    }
    return bit_integer;
}

std::ostream &operator<<(std::ostream&cout, const LinearFSR &lfsr) {
    return cout << lfsr.bit_string;
}


