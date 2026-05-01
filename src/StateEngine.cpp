#include "StateEngine.h"

/** @copydoc StateEngine::StateEngine(float xStart, float yStart, float angleStart) */
StateEngine::StateEngine(float xStart, float yStart, float angleStart) : angleIncrement(25), stepSize(50)
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
void StateEngine::process(Fractal f)
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
