#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "Hello world!");

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}

// g++ sfml.cpp --std=c++14 -I/opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-window -lsfml-system -lsfml-graphics
