#ifndef FUNCTIONS_HPP

#define FUNCTIONS_HPP


#include <string>

#include <SFML/Graphics.hpp>

using namespace sf;

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
void img_to_grayscale(Image& src);
/// <summary>
/// Drops the resolution on the Image by setting each pixel in a 7x7 chunk to the average.
/// </summary>
/// <param name="src">Source Image</param>
/// <returns>New Image with lowered resolution</returns>
void res_drop(Image& src);
/// <summary>
/// Takes the average of a 7x7 chunk of pixels.
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="x">Initial x posiiton</param>
/// <param name="y">Initial y position</param>
/// <param name="s">Initial RGB channel</param>
/// <returns>Average pixel value</returns>
const int get_avg(Image& src, const int& x,const int& y,const int& s);
/// <summary>
/// Sets 7x7 chunk to specified value.
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="x">Initial x position</param>
/// <param name="y">Initial y position</param>
/// <param name="val">Value to set pixel to</param>
void setChunk(Image& src, const int& x, const int& y, Color& color);
/// <summary>
/// Pixel's value in grey scale is mapped to ASCII character based on article by Paul Bourke.
/// </summary>
/// <param name="value">Pixel value on grayscale</param>
/// <returns>ASCII character within ranges 32-126</returns>
const char ascii_mapper(const int& value);
/// <summary>
/// Creates ascii art string for passed image.
/// </summary>
/// <param name="src">Source Image</param>
/// <returns>Ascii art string</returns>
const std::string create_ascii(Image& src);

#endif