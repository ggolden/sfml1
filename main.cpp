#include <SFML/Graphics.hpp>
#include <iostream>

int main1() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML 1");

    sf::CircleShape shape1;
    shape1.setRadius(40.f);
    shape1.setPosition(0.f, 0.f);
    shape1.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::X) {
                //std::cout << event.key.code << std::endl;
                window.close();
            }
            // std::cout << event.type << std::endl;
        }

        window.clear();
        window.draw(shape1);
        window.display();

        shape1.move(0.01f, 0.01f);
    }
}

int main2() {
    sf::RenderWindow window{sf::VideoMode(1920, 1080), "SFML 2"};
    std::string name = "../Mushroom.png";

    sf::Texture texture;
    if (!texture.loadFromFile(name)) {
        std::cout << "cannot load file: " << name << std::endl;
    }

    sf::Sprite sprite{texture};
    sf::Vector2u size = texture.getSize();
    sprite.setOrigin(size.x / 2, size.y / 2);

    // sprite.setColor(sf::Color::Blue);

    sf::Vector2f increment{0.4f, 0.4f};

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if ((sprite.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) ||
            (sprite.getPosition().x - (size.x / 2) < 0 && increment.x < 0)) {
            increment.x = -increment.x;
        }

        if ((sprite.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) ||
            (sprite.getPosition().y - (size.y / 2) < 0 && increment.y < 0)) {
            increment.y = -increment.y;
        }

        sprite.setPosition(sprite.getPosition() + increment);

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

int main() {
    main2();
}