#include "GameLoop.h"

/** @copydoc GameLoop::GameLoop() */
GameLoop::GameLoop()
{
    window = new sf::RenderWindow(sf::VideoMode({1423, 904}), "L-System");
}

/** @copydoc GameLoop::~GameLoop() */
GameLoop::~GameLoop()
{
}

/** @copydoc GameLoop::run() */
void GameLoop::run()
{

    StateEngine engine(window->getSize().x / 2, window->getSize().y, -90.f);

    // events
    while (window->isOpen())
    {

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }

        // update
        for(int i = 0; i < 1; ++i)
        {
            engine.update();
        }

        auto lines = engine.getLines();

        window->clear();

        window->draw(engine.getVertexArray());

        window->display();
    }
}
