#include "Fractal.h"

/**
 * @brief Gets axiom
 * 
 * @return std::string Axiom as a string.
 */
std::string Fractal::getAxiom()
{
    return axiom;
}

/**
 * @brief Finds each instance of Axiom in string and replaces
 * it with the Rule.
 * 
 */
void Fractal::searchAndReplace()
{
    std::string next;

    for (char c: axiom)
    {
        auto it = rule.find(c);

        if (it != rule.end())
        {
            next += " ";
            next += it->second;
            next += " ";
        }
        else
        {
            next += c;
        }
    }

    axiom = std::move(next);
}
