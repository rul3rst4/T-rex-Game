#include <SFML/Graphics.hpp>
#include "Dino.cpp"
#include "Level.cpp"

class Game
{
  public:
    Game() : window(sf::VideoMode(816, 600), "Flow")
    {
        window.setFramerateLimit(60);
        frames = 0;
        loop();
    }

    ~Game() {}

    void loop()
    {
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
            update();
            render();
        }
    }

    void update()
    {
        lvl.update();
        enemy.update(frames);
        dino.keyboard_input();
        dino.update(frames , enemy);
        frames = ((frames + 1) % 60) + 1;
    }

    void render()
    {
        window.clear(sf::Color(200, 200, 200));
        lvl.draw(&window);
        enemy.draw(&window);
        dino.draw(&window);
        window.display();
    }

  private:
    sf::RenderWindow window;
    Dino dino;
    Level lvl;
    Obstacles enemy;
    int frames;
};

//g++ main.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-system -lsfml-window