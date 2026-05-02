#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameLoop.h"
#include "StateEngine.h"
#include "Fractal.h"

using std::cout;
using std::endl;

int main()
{

	// GameLoop g;

	// g.run();

	
    // Fractal f("F", {{'F', "F[+F][-F]"}});
	
    // // cout << f.getAxiom() << endl;
	
    // for (size_t i = 0; i < 3; ++i)
    // {
		
	// 	f.searchAndReplace();
    //     // cout << f.getAxiom() << endl;
    // }
	
    StateEngine engine(360, 200, -90.f);

	engine.process();
    engine.printList();

	return 0;
}
