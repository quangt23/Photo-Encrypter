// Copyright 2023
// Quang Tran
#include "LinearFSR.hpp"
#include "Encrypt.hpp"

namespace Encrypt {
    void transform(sf::Image& image, LinearFSR* LFSR) {
        // p is a pixelimage.getPixel(x, y);
        sf::Color p;
        sf::Vector2u size = image.getSize();
        // In order to encrypt the whole image instead of upper left,
        // We have to get the size of the image.
        for (unsigned int x = 0; x < size.x; x++) {
            for (unsigned int y = 0; y < size.y; y++) {
                p = image.getPixel(x, y);
                // XOR rgb w newly generated 8 bit integer
                p.r ^= LFSR -> generate(8);
                p.g ^= LFSR -> generate(8);
                p.b ^= LFSR -> generate(8);
                image.setPixel(x, y, p);
            }
        }
    }
}  // namespace Encrypt
