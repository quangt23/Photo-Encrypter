// Copyright 2023 Quang Tran
#pragma once
#include <iostream>
#include <string>
#include <bitset>

class LinearFSR {
 public:
        // Constructor to create LFSR with the given initial seed
        explicit LinearFSR(std::string seed);
        // Simulate one step and return the new bit as 0 or 1
        int step();
        // Simulate k steps and return a k-bit integer
        int generate(int k);

        void reverseBitString();
        friend std::ostream& operator<<
        (std::ostream& cout, const LinearFSR& lfsr);
 private:
        static const int kBit_Size = 16;
        std::bitset<kBit_Size> bit_string;
};
std::ostream& operator<<(std::ostream&, const LinearFSR& lfsr);
