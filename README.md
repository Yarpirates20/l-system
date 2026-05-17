# L-System Tree Simulation

From _Wikipedia_:

>    "An L-system consists of an alphabet of symbols that can be used to make strings, a collection of production rules that expand each symbol into some larger string of symbols, an initial "axiom" string from which to begin construction, and a mechanism for translating the generated strings into geometric structures."

This program is the mechanism mentioned above. It is a simulation of the tree or fractal that are created from the different axioms and production rules.

## Examples

### Sierpinski triangle
   - **axiom**: F-G-G
   - **rules**: (F -> F-G+F+G-F), (G -> GG)
   - **angle**: 120°

IMAGE

### Fractal Plant
   - **axiom**: -X
   - **rules**: (X -> F+[[X]-X]-F[-FX]+X), (F -> FF)
   - **angle**: 25°

IMAGE

This project used the CMake SFML template for the graphics, which made it super simple and easy to work on.

