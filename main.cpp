#include <SFML/Graphics.hpp>

int main() {
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
            }
        }

        window.clear();
        window.draw(shape1);
        window.display();

        shape1.move(0.01f, 0.01f);
    }
}
