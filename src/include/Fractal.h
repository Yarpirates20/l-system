#ifndef FRACTAL_H
#define FRACTAL_H

#include <string>
#include <map>

/**
 * @brief A class that holds the axiom as a string and the rules for search and 
 * replace.
 * 
 */
class Fractal
{
private:
    std::string axiom;
    std::map<char, std::string> rule;

public:
    /**
     * @brief Construct a new Fractal object.
     * 
     * @param a String that holds the desired starting axiom.
     * @param r A map of what to replace a particular character with.
     */
    Fractal(std::string a, std::map<char, std::string> r) : axiom(a), rule(r) {}

    /**
     * @brief Get the Axiom object.
     * 
     * @return std::string Returns the axiom as a string.
     */
    std::string getAxiom();

    /**
     * @brief Replaces each instance of a character with the mapped rule and 
     * updates the axiom.
     * 
     */
    void searchAndReplace();
};

#endif // FRACTAL_H