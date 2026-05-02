#include "GameLoop.h"

/** @copydoc GameLoop::GameLoop() */
GameLoop::GameLoop()
{
    window = new sf::RenderWindow(sf::VideoMode({640, 480}), "L-System");
}

/** @copydoc GameLoop::~GameLoop() */
GameLoop::~GameLoop()
{
}

/** @copydoc GameLoop::run() */
void GameLoop::run()
{

    StateEngine engine(window->getSize().x / 2, window->getSize().y, -90.f);

    engine.process();

    auto lines = engine.getLineList();

    // events
    while (window->isOpen())
    {
        while (window->isOpen())
        {
            while (const std::optional event = window->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window->close();
            }
        }

        // update
        window->clear();

        // render
        for (auto &&j : lines)
        {
            sf::VertexArray l{sf::PrimitiveType::Lines, 2};
            l[0].position = sf::Vector2f(j.x1, j.y1);
            l[1].position = sf::Vector2f(j.x2, j.y2);

            l[0].color = sf::Color::Cyan;
            l[1].color = sf::Color::Cyan;

            window->draw(l);
        }

        window->display();
    }
}
