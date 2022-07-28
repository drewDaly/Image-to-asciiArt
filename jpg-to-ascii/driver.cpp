#include <iostream>
#include "SFML/Graphics.hpp"
#include "functions.hpp"


int main()
{
	sf::Image img;
	img.loadFromFile("blindman's meal.jpg");
	std::cout << (char)img.getPixel(49, 49).g << std::endl;
	system("pause>0");
	return 0;
}

