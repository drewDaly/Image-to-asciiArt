#include "pch.h"
#include "CppUnitTest.h"
#include "../jpg-to-ascii/functions.cpp"
#include <vector>
using namespace std;
using namespace sf;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		TEST_METHOD(GET_AVG) {
			Image img;
			img.create(7, 7, Color(255, 0, 255));
			int avg = get_avg(img, 0, 0);
			Assert::AreEqual(avg, 255);
		};
		TEST_METHOD(ASCII_MAP) {
			char c = ascii_mapper(255);
			Assert::AreEqual(c, '.');
			char h = ascii_mapper(0);
			Assert::AreEqual(h, '$');
		};
		TEST_METHOD(IMG_TO_GRAYSCALE) {
			Image img;
			img.create(49, 49, Color(255, 0, 255));
			img_to_grayscale(img);
			Assert::AreNotEqual(255, (int)img.getPixel(0, 0).r);
			Assert::AreNotEqual(255, (int)img.getPixel(48, 48).r);
		};
		TEST_METHOD(CREATE_ASCII) {
			Image img;
			img.create(49, 49, Color(255, 0, 255));
			std::string lemon = create_ascii(img);
			Assert::AreNotEqual((std::string)"", lemon);
		}
	};
}
