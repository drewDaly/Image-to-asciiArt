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
/// <param name="src">Source Image</param>
/// <returns>New Grayscale Image</returns>
const CImg<unsigned char> img_to_grayscale(CImg<unsigned char>& src);
/// <summary>
/// Drops the resolution on the Image by setting each pixel in a 7x7 chunk to the average.
/// </summary>
/// <param name="src">Source Image</param>
/// <returns>New Image with lowered resolution</returns>
const CImg<unsigned char> res_drop(CImg<unsigned char>& src);
/// <summary>
/// Takes the average of a 7x7 chunk of pixels.
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="x">Initial x posiiton</param>
/// <param name="y">Initial y position</param>
/// <param name="s">Initial RGB channel</param>
/// <returns>Average pixel value</returns>
const int get_avg(CImg<unsigned char>& src, const int& x,const int& y,const int& s);
/// <summary>
/// Sets 7x7 chunk to specified value.
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="x">Initial x position</param>
/// <param name="y">Initial y position</param>
/// <param name="s">Initial RGB channel</param>
/// <param name="val">Value to set pixel to</param>
void setChunk(CImg<unsigned char>& src, const int& x, const int& y, const int& s, const int& val);

#endif