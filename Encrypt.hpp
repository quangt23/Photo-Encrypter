// Copyright 2023 Quang Tran
#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Encrypt {
    // Transforms image using LinearFSR
    void transform(sf::Image& image, LinearFSR* LFSR);
    // Display an encrypted copy of the picture, using the LFSR to do the
    // encryption
}
