#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>

class Obstacles
{
  public:
    Obstacles() : rect(0, 0, 50, 50)
    {
        texture.loadFromFile("./Images/enemies.png");
        enemies.setTexture(texture);
        enemies.setTextureRect(rect);
        enemies.setPosition(866, 550);
        srand(time(NULL));
        enemy_on_screen = false;
        position = sf::Vector2f(enemies.getPosition());
    }

    ~Obstacles()
    {
    }

    void draw(sf::RenderWindow *window)
    {
        window->draw(enemies);
    }

    void update(int frames)
    {
        int k = rand() % 4;

        if (frames % 6 == 0 && !enemy_on_screen)
        {
            switch (k)
            {
            case 0:
                rect = sf::IntRect(0, 0, 50, 50);
                break;

            case 1:
                rect = sf::IntRect(50, 0, 50, 50);
                break;

            case 2:
                rect = sf::IntRect(0, 50, 50, 50);
                break;

            case 3:
                rect = sf::IntRect(50, 50, 50, 50);
                break;
            }
            enemy_on_screen = true;
        }

        enemies.setTextureRect(rect);

        if (enemy_on_screen)
        {
            position.x = position.x - 4;
            enemies.setPosition(position);

            if (position.x <= -50)
            {
                enemy_on_screen = false;
                enemies.setPosition(866, 550);
            }
        }
        position = sf::Vector2f(enemies.getPosition());
    }

  private:
    sf::Texture texture;
    sf::Sprite enemies;
    sf::IntRect rect;
    sf::Vector2f position;
    bool enemy_on_screen;
};