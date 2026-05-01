#ifndef STATEENGINE_H
#define STATEENGINE_H

#include "Fractal.h"

#include <stack>
#include <string>
#include <cmath>
#include <vector>

/** 
 * Struct holding the coordinates and angles to push/pop off stack.
 */
struct State
{
    float x;
    float y;
    float angle;
};

struct Line
{
    float x1, y1;
    float x2, y2;
};

/**
 * @brief Translates string of characters into geometric data
 * (coordinates and lines) that can be understood by a screen.
 * 
 */
class StateEngine
{
private:
    std::stack<State> s;
    const float angle = 25.0;
    const float stepSize = 50.0;
    State currentState;
    std::vector<Line> lineList;

public:
 
    /**
     * @brief Construct a new State Engine object
     * 
     * @param xStart    Starting x coordinates in window.
     * @param yStart    Starting y coordinates in window.
     * @param angleStart Starting angle in degrees.
     */
    StateEngine(float xStart, float yStart, float angleStart);

    /**
     * @brief Pushs a State struct onto the stack.
     * 
     */
    void pushState();

    /**
     * @brief Pops the top State struct on the stack.
     * 
     */
    void popState();

    /**
     * @brief Rotates drawing angle by fixed amount.
     * 
     * @param c Character '+' or '-'.
     */
    void rotateAngle(char c);

    /**
     * @brief Main loop that iterates through string character by 
     * character.
     * 
     * @param f 
     */
    void process(Fractal f);

    /**
     * @brief Triggered by Fractal Key char. 
     * 
     * Uses trigonometry to move x & y coordinates.
     * 
     */
    void stepForward();

    /**
     * @brief Get the Lines object.
     * 
     * @return std::vector<Line> A vector of Line structs.
     */
    std::vector<Line> getLines();

    /**
     * @brief Helper function to convert degrees to radians.
     * 
     * @param degrees Number of degrees to convert.
     * @return float Converted float as radians.
     */
    float degreeToRadians(float degrees);
};

#endif // STATEENGINE_H