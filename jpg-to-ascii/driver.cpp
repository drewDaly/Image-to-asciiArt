#include <iostream>
#include<CImg.h>
#include "functions.hpp"
using namespace cimg_library;

int main()
{
	CImg<unsigned char> image("./images/guitar man.jpg");
	image.display();
    return 0;
}

