#include <iostream>
#include "SFML/Graphics.hpp"
#include "functions.hpp"


int main()
{
	std::string path;
	std::cout << "Enter the name of the file (LOCATED IN IMAGES & ONE WORD) that you wish to convert: ";
	std::cin >> path;
	std::cout << '\n';
	std::cout << "Enter the path of the text file (LOCATED IN RESULTS) you wish to send your ASCII Art to: ";
	std::string out;
	std::cin >> out;
	std::cout << '\n';
	sf::Image img;
	img.loadFromFile("Images/" + path);
	ascii_txtFile(img, "Results/" + out);
	std::cout << "Results should be located in Results/" << out;
	system("pause>0");
	return 0;
}

