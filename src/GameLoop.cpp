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
    Fractal f("F", {{'F', "F[+F][-F]"}});

    // cout << f.getAxiom() << endl;

    for (size_t i = 0; i < 3; ++i)
    {

        f.searchAndReplace();
        // cout << f.getAxiom() << endl;
    }

    StateEngine engine(window->getSize().x /2, window->getSize().y, -90.f);
    engine.process();
    engine.printStack();

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
        window->display();
    }
}
