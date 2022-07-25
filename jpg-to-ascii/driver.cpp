#include <iostream>
#include<CImg.h>
#include "functions.hpp"
#include <vector>
using namespace cimg_library;

int main()
{
	const int width = 3,
		height = 2;
	std::vector<unsigned char> w{
255,0,0,0,255,255,
0,255,0,255,0,255,
0,0,255,255,255,0
	};

	CImg<unsigned char> image((unsigned char*)&w[0], width, height, 1, 3);
	CImg<unsigned char> img = img_to_grayscale(image);
	image.display();
	img.display();
    return 0;
}

