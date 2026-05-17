#include "StateEngine.h"
#include <iostream>

/** @copydoc StateEngine::StateEngine(float xStart, float yStart, float angleStart) */
StateEngine::StateEngine(float xStart, float yStart, float angleStart) : angleIncrement(25), stepSize(15), f(spawn()), treeVA(sf::PrimitiveType::Lines, 2)
{

    angleIncrement = degreeToRadians(angleIncrement);

    angleStart = degreeToRadians(angleStart);

    currentState = {xStart, yStart, angleStart};
}

/** @copydoc StateEngine::pushState() */
void StateEngine::pushState()
{
    s.push(currentState);
}

/** @copydoc StateEngine::popState() */
void StateEngine::popState()
{
    if (!s.empty())
    {
        currentState = s.top();
        s.pop();
    }
}

/** @copydoc StateEngine::rotateAngle(char c) */
void StateEngine::rotateAngle(char c)
{
    if (c == '+')
    {
        currentState.angle += angleIncrement;
    }
    else if (c == '-')
    {
        currentState.angle -= angleIncrement;
    }
}

/** @copydoc StateEngine::process(Fractal f) */
void StateEngine::process()
{
    const auto &rules = f.getRule();

    for (const auto &i : f.getAxiom())
    {
        if (rules.find(i) != rules.end())
        {
            stepForward();
        }
        else if (i == '+')
        {
            currentState.angle += angleIncrement;
        }
        else if (i == '-')
        {
            currentState.angle -= angleIncrement;
        }
        else if (i == '[')
        {
            pushState();
        }
        else if (i == ']')
        {
            popState();
        }
    }
}

/** @copydoc StateEngine::update() */
void StateEngine::update()
{
    const auto &rules = f.getRule();

    if (currentCharIndex < f.getAxiom().length())
    {
        char k = f.getAxiom()[currentCharIndex];
        
        if (rules.find(k) != rules.end())
        {
            stepForward();
        }
        else if (k == '+')
        {
            currentState.angle += angleIncrement;
        }
        else if (k == '-')
        {
            currentState.angle -= angleIncrement;
        }
        else if (k == '[')
        {
            pushState();
        }
        else if (k == ']')
        {
            popState();
        }

        currentCharIndex++;
    }
}

/** @copydoc StateEngine::stepForward() */
void StateEngine::stepForward()
{
    float nextX = currentState.x + stepSize * cos(currentState.angle);

    float nextY = currentState.y + stepSize * sin(currentState.angle);

    sf::Vertex start{sf::Vector2f(currentState.x, currentState.y), sf::Color::Cyan};

    sf::Vertex end{sf::Vector2f(nextX, nextY), sf::Color::Cyan};

    treeVA.append(start);
    treeVA.append(end);

    // Update current position to new end point
    currentState.x = nextX;
    currentState.y = nextY;
}

/** @copydoc StateEngine::getLines() */
std::vector<Line> StateEngine::getLines()
{
    return lineList;
}

/** @copydoc StateEngine::degreeToRadians(float degrees) */
float StateEngine::degreeToRadians(float degrees)
{
    return (degrees * M_PI) / 180;
}

/** @copydoc StateEngine::spawn() */ 
Fractal StateEngine::spawn()
{
    Fractal frac("-X", {{'X', "F+[[X]-X]-F[-FX]+X"}, {'F', "FF"}});

    for (size_t i = 0; i < 6; ++i)
    {
        frac.searchAndReplace();
    }

    return frac;
}

/** @copydoc StateEngine::printList() */
void StateEngine::printList()
{
    for (auto &&i : lineList)
    {
        std::cout << "Start: (" << i.x1 << ", " << i.y1 << ")\n";
        std::cout << "End: (" << i.x2 << ", " << i.y2 << ")\n\n";
    }
}

/** @copydoc StateEngine::getVertexArray() const */
const sf::VertexArray &StateEngine::getVertexArray() const
{
    return treeVA;
}
