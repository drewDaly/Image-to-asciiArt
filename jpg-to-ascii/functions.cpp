#include "functions.hpp";
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

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

const int get_avg(Image& src, const int& x, const int& y, std::vector<int> factors) {
	int avg = 0;
	for (int w = 0; w < factors.at(0); ++w) {
		for (int h = 0; h <factors.at(1); ++h) {
			avg += src.getPixel(x + w, y + h).r;
		}
	}
	return (int) avg / (factors.at(0) * factors.at(1));
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
	std::vector<int> factors;
	if (src.getSize().x < 500 || src.getSize().y < 400) {
		factors.push_back(1), factors.push_back(1);
	}
	else {
		factors.push_back((int)src.getSize().x / 500),
			factors.push_back((int)src.getSize().y / 400);
	}
	std::string ascii_art = "";
	img_to_grayscale(src);
	for (int h = 0; h < src.getSize().y - factors.at(1); h += factors.at(1)) {
		for (int w = 0; w < src.getSize().x - factors.at(0); w += factors.at(0)) {
			int chunkAvg = get_avg(src, w, h, factors);
			ascii_art += ascii_mapper(chunkAvg);
		}
		ascii_art += '\n';
	}
	return ascii_art;
}

void ascii_txtFile(Image& src, const std::string& path) {
	std::string asciiArt = create_ascii(src);
	std::ofstream ofs;
	ofs.open(path);
	if (ofs.is_open()) {
		ofs << asciiArt;
		ofs.close();
	}
}