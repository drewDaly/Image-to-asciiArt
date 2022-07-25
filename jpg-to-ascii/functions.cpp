#include "functions.hpp";
#include "CImg.h"
#include <fstream>

const CImg<unsigned char>& img_to_greyscale(char* input) {
	const float redCoeff = .2126,
	 greenCoeff = .7152,
	 blueCoeff = .0722;
	CImg<unsigned char> src(input), img(src.width(), src.height(), 1, 1);
	for (int w = 0; w < img.width(); ++w) {
		for (int h = 0; h < img.height(); ++h) {
			const float valR = src(w, h, 0),
				valG = src(w, h, 1),
				valB = src(w, h, 1);
			int greyVal = (valR * redCoeff) + (valG * greenCoeff) + (valB * blueCoeff);
			img.set_linear_atXY(greyVal, w, h);
		}
	}
	return img;
}
