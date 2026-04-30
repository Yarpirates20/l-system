#ifndef STATEENGINE_H
#define STATEENGINE_H

#include "State.h"

#include <stack>
#include <string>

class StateEngine
{
private:
    std::stack<State> s;

public:
    /**
     * @brief Construct a new State Engine object
     * 
     * @param a Axiom 
     */
    StateEngine() {}

    /**
     * @brief Pushs a State struct onto the stack.
     * 
     * @param fractalState State to push.
     */
    void push(State fractalState);

    /**
     * @brief Pops the top State struct on the stack.
     * 
     * @return State The popped State struct.
     */
    State pop();

    
};

#endif // STATEENGINE_H