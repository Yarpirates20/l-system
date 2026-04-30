#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SFML/Graphics.hpp>
#include "StateEngine.h"
#include "Fractal.h"

class GameLoop
{
    private:
        sf::RenderWindow *window;
        StateEngine *stateStack;

    public:
        /**
         * @brief Construct a new Game Loop object
         * 
         */
        GameLoop();

        /**
         * @brief Destroy the Game Loop object
         * 
         */
        ~GameLoop();

        /**
         * @brief Run main graphics rendering loop.
         * 
         */
        void run();        

};

#endif // GAMELOOP_H