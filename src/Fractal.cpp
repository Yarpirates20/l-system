#include "Fractal.h"

/** @copydoc Fractal::getAxiom() */
std::string Fractal::getAxiom()
{
    return axiom;
}

/** @copydoc Fractal::searchAndReplace() */
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
