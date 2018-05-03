#include <SFML/Graphics.hpp>
#include "Obstacles.cpp"

class Dino
{
  public:
    Dino() : velocity(0, 0),
             gravity(0, 0.98),
             rect(0, 0, 50, 43)
    {
        jump = false;
        ground = true;
        texture.loadFromFile("./Images/dino.png");
        dino.setTexture(texture);
        dino.setTextureRect(rect);
        dino.setPosition(50, 550);
        position = sf::Vector2f(dino.getPosition());
        t = 0;
    }

    ~Dino() {}

    void draw(sf::RenderWindow *window)
    {
        window->draw(dino);
    }

    void keyboard_input()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground)
        {
            velocity.y = -16;
            jump = true;
            ground = false;
        }
    }

    void update(int frames , Obstacles enemy)
    {
        position += velocity;
        if (!ground)
        {
            velocity += gravity;
            if (position.y >= 550)
            {
                position.y = 550;
                ground = true;
                jump = false;
                velocity.y = 0;
            }
        }

        rect = sf::IntRect(t, 0, 50, 43);

        if (frames % 12 == 0)
            t = (t + 50) % 100;

        dino.setTextureRect(rect);
        dino.setPosition(position);

        if (ground)
            velocity = sf::Vector2f(0, 0);
    }

  private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
    sf::Texture texture;
    sf::Sprite dino;
    sf::IntRect rect;
    int t;
    bool jump;
    bool ground;
};