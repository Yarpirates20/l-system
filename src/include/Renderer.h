#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "StateEngine.h"
#include <vector>

class Renderer
{
    private:
        std::vector<Line> lines;
        sf::VertexArray line{sf::PrimitiveType::Lines, 2};

    public:

};

#endif // RENDERER_H