#include <SFML/Graphics.hpp>
#include "Fractal.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Fractal f("F", {{'F', "F[+F][-F]"}});

	cout << f.getAxiom() << endl;

	for (size_t i = 0; i < 3; ++i)
	{

		f.searchAndReplace();
		cout << f.getAxiom() << endl;
	}

	/* 	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
		sf::CircleShape shape( 100.f );
		shape.setFillColor( sf::Color::Green );

		while ( window.isOpen() )
		{
			while ( const std::optional event = window.pollEvent() )
			{
				if ( event->is<sf::Event::Closed>() )
					window.close();
			}

			window.clear();
			window.draw( shape );
			window.display();
		} */
}
