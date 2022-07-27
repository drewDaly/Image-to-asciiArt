#include "functions.hpp";
#include <SFML/Graphics.hpp>
using namespace sf;

void img_to_grayscale(Image& src) {
	for (int w = 0; w < src.getSize().x; ++w) {
		for (int h = 0; h < src.getSize().y; ++h) {
			const int valR = src.getPixel(w, h).r,
				valG = src.getPixel(w, h).g,
				valB = src.getPixel(w, h).b;
			int grayVal = (int)((valR * .2126) + (valG * .7152) + valB * .0722);
			src.setPixel(w,h, Color(grayVal, grayVal, grayVal));
		}
	}
}



const int get_avg(Image& src, const int& x, const int& y) {
	int avg;
	if (src.getSize().x < 7 || src.getSize().y < 7) throw "image too small";
	for (int w = 0; w < 7; ++w) {
		for (int h = 0; h < 7; ++h) {
			if (w == 0 && h == 0) avg = src.getPixel(x + w, y + h).r;
			else avg += src.getPixel(x + w, y + h).r;
		}
	}
	return (int) avg / 49;
}

const char ascii_mapper(const int& value) {
	char scale[] = { '$', '@', 'B', '%', '8', '&', 'W', 'M',
		'#','*', 'o', 'a', 'h', 'k','b','d','p','q','w','m','Z',
		'O','0','Q','L','C','J','U','Y','X','z','c','v','u','n',
		'x','r','j','f','t','/',char(92), '|', '(',')','1',
		'{','}','[',']','?','-','_','+','~','<','>','i','!','l',
		'I',';',':',',','"','^','`',char(39),'.' };
	float coeff = 3.75;
	int vl = (int)value / coeff;
	return scale[vl];
}
const std::string create_ascii(Image& src) {
	std::string ascii_art = "";
	img_to_grayscale(src);
	for (int h = 0; h < src.getSize().y; h += 7) {
		for (int w = 0; w < src.getSize().x; w += 7) {
			int chunkAvg = get_avg(src, w, h);
			ascii_art += ascii_mapper(chunkAvg);
		}
		ascii_art += '\n';
	}
	return ascii_art;
}