#ifndef FRACTAL_H
#define FRACTAL_H

#include <string>
#include <map>

class Fractal
{
private:
    std::string axiom;
    std::map<char, std::string> rule;

public:
    Fractal(std::string a, std::map<char, std::string> r) : axiom(a), rule(r) {}

    std::string getAxiom();

    void searchAndReplace();
};

#endif // FRACTAL_H