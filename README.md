# L-System Tree Simulation

From _Wikipedia_:

>    "An L-system consists of an alphabet of symbols that can be used to make strings, a collection of production rules that expand each symbol into some larger string of symbols, an initial "axiom" string from which to begin construction, and a mechanism for translating the generated strings into geometric structures."

This program is the mechanism mentioned above. It is a simulation of the tree or fractal that are created from the different axioms and production rules.

## Examples

### Sierpinski triangle
   - **axiom**: F-G-G
   - **rules**: (F -> F-G+F+G-F), (G -> GG)
   - **angle**: 120°

<img width="1136" height="932" alt="Image" src="https://github.com/user-attachments/assets/9a703ecc-60a7-4c20-8253-b5760b3f2729" />

### Fractal Plant
   - **axiom**: -X
   - **rules**: (X -> F+[[X]-X]-F[-FX]+X), (F -> FF)
   - **angle**: 25°

<img width="1436" height="935" alt="Image" src="https://github.com/user-attachments/assets/d5e3c323-1613-4050-a2b6-8d98f14cb355" />


I used the [CMake SFML Template](https://github.com/SFML/cmake-sfml-project) for the graphics, which made it super simple and easy to work on.

