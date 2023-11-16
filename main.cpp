// Copyright 2023
// Quang Tran
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LinearFSR.hpp"
#include "Encrypt.hpp"

using Encrypt::transform;

int main(int argc, char* argv[]) {
    // For arguments
    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    std::string seed = argv[3];

    LinearFSR LFSR(seed);

    sf::Image image;
    if (!image.loadFromFile(inputFileName))
        return -1;

    // Render Original
    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Encrypt
    transform(image, &LFSR);

    // Render Encrypt
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");
    sf::Texture texture2;
    texture2.loadFromImage(image);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window2.close();
        }

        window1.clear();
        window1.draw(sprite);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    if (!image.saveToFile(outputFileName))
        return -1;

    return 0;
}
