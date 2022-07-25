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

const CImg<unsigned char> res_drop(CImg<unsigned char>& src) {
	if (src.width() < 7 || src.height() < 7) throw "image too small";
	CImg<unsigned char> img(src.width(), src.height(), 1, src.spectrum(), 0);
	for (int w = 0; w < img.width() - 7; w += 7) {
		for (int h = 0; h < img.width() - 7; h += 7) {
			for (int s = 0; s < img.spectrum(); ++s) {
				try {
					int avg = get_avg(src ,w, h, s);
					setChunk(img, w, h, s, avg);
				}
				catch (...) {
					throw "err";
				}
			}
		}
	}
	return img;
}

const int get_avg(CImg<unsigned char>& src, const int& x, const int& y, const int& s) {
	int avg;
	if (src.width() < 7 || src.height() < 7) throw "image too small";
	for (int w = 0; w < 7; ++w) {
		for (int h = 0; h < 7; ++h) {
			if (w == 0 && h == 0) avg = src(x, y, s);
			else avg += src(w + x, h + y, s);
		}
	}
	return (int)avg / 49;
}


void setChunk(CImg<unsigned char>& src, const int& x, const int& y, const int& s, const int& val) {

}