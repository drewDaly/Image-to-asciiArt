#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <string>;
#include <CImg.h>;
using namespace cimg_library;

// create the greyscale img
// drop the resolution on the greyscale by grabbing 7x7 blocks and averaging them
// convert the 7x7 block into an ascii character (store in a char*[][]?)
// find averages for 7x7 blocks of src img's RGB (store in <int,int, int>*[][]?)
// draw_text() and delete ascii[] delete RGB[] at the same time
// save that new img file

/// <summary>
/// Converts Image to Grayscale Image
/// </summary>
/// <param name="src">Image to be converted</param>
/// <returns>Grayscale Image</returns>
const CImg<unsigned char> img_to_grayscale(CImg<unsigned char>& src);
const CImg<unsigned char> res_drop(CImg<unsigned char>& src);
const int get_avg(CImg<unsigned char>& src, const int& x,const int& y,const int& s);
void setChunk(CImg<unsigned char>& src, const int& x, const int& y, const int& s, const int& val);

#endif