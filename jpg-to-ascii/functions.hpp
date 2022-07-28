#ifndef FUNCTIONS_HPP

#define FUNCTIONS_HPP


#include <string>

#include "SFML/Graphics.hpp"

using namespace sf;


/// <summary>
/// Converts Image to Grayscale Image
/// </summary>
/// <param name="src">Source Image</param>
/// <returns>New Grayscale Image</returns>
void img_to_grayscale(Image& src);
/// <summary>
/// Takes the average of a chunk of pixels.
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="x">Initial x posiiton</param>
/// <param name="y">Initial y position</param>
/// <param name="factors">Dimensions of pixels that are averaged together.</param>
/// <returns>Average pixel value</returns>
const int get_avg(Image& src, const int& x,const int& y, std::vector<int> factors);

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
/// <summary>
/// Saves ascii art to specified .txt file
/// </summary>
/// <param name="src">Source Image</param>
/// <param name="path">.txt file path</param>
void ascii_txtFile(Image& src, const std::string& path);
#endif