#include <SFML/Graphics.hpp>
#include <iostream>

class Level
{
  public:
    Level()
    {
        bg.loadFromFile("./Images/Ground.png");
        bg.setRepeated(1);
        background.setTexture(bg);
        background.setOrigin(0, 0);
        background.scale(1.5, 2);
        background.setTextureRect(sf::IntRect(0, 0, 1632, 26));
        background.setPosition(0, 574);
        cont = 2;
        position = sf::Vector2f(background.getPosition());
    }

    ~Level() {}

    void draw(sf::RenderWindow *window)
    {
        window->draw(background);
    }

    void update()
    {
        position.x = position.x - 4;

        if (position.x == -816)
            position.x = 0;

        background.setPosition(position);

        position = sf::Vector2f(background.getPosition());
    }

  private:
    sf::Texture bg;
    sf::Sprite background;
    int cont;
    sf::Vector2f position;
};