#include "pch.h"
#include "CppUnitTest.h"
#include "../jpg-to-ascii/functions.cpp"
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(GET_AVG)
		{
			const int width = 7,
				height = 7;
			std::vector<unsigned char> w{
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49
			};
			CImg<unsigned char> image((unsigned char*)&w[0], width, height, 1, 3);
			Assert::AreEqual(get_avg(image, 0, 0, 0), 49);
		}
		TEST_METHOD(SET_CHUNK) {
			const int width = 7,
				height = 7;
			std::vector<unsigned char> w{
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49,
				49, 49, 49
			};
			CImg<unsigned char> image((unsigned char*)&w[0], width, height, 1, 3);
			setChunk(image, 0, 0, 0, 29);
			Assert::AreEqual(int(image(0, 0, 0)), 29);
			setChunk(image, 0, 0, 1, 47);
			Assert::AreEqual(int(image(0, 0, 1)), 47);
		}
	};
}
