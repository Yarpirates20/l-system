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
    while (window->isOpen())
    {
        // events here if adding later

        // update
        window->clear();

        //render
        window->display();
    }
    
}
