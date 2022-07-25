#include "functions.hpp";
#include "CImg.h"
#include <fstream>

const CImg<unsigned char> img_to_grayscale(CImg<unsigned char>& src) {
	CImg<unsigned char> img(src.width(), src.height(), 1, 1, 0);
	for (int w = 0; w < img.width(); ++w) {
		for (int h = 0; h < img.height(); ++h) {
			const int valR = src(w, h, 0),
				valG = src(w, h, 1),
				valB = src(w, h, 2);
			int greyVal = (int)((valR * .2126) + (valG * .7152) + valB * .0722);
			img(w, h, 0, 0) = greyVal;
		}
	}
	return img;
}
