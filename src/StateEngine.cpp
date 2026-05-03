#include "StateEngine.h"
#include <iostream>

/** @copydoc StateEngine::StateEngine(float xStart, float yStart, float angleStart) */
StateEngine::StateEngine(float xStart, float yStart, float angleStart) : angleIncrement(25), stepSize(15), f(spawn())
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

/** @copydoc StateEngine::stepForward() */
void StateEngine::stepForward()
{
    float nextX = currentState.x + stepSize * cos(currentState.angle);

    float nextY = currentState.y + stepSize * sin(currentState.angle);

    // Save line from current (start) to next (end)
    lineList.push_back({currentState.x, currentState.y, nextX, nextY});

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
    Fractal frac("-X", {{'X', "F+[[X]-X]-F[-FX]+X"},{'F', "FF"}});

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

/** @copydoc StateEngine::getLineList() */
std::vector<Line> StateEngine::getLineList()
{
    return lineList;
}
