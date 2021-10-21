#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <string>

#define byte unsigned char

struct Pixel
{
	byte r;
	byte g;
	byte b;
	byte a;

	Pixel(byte red, byte green, byte blue, byte alpha) : r(red), g(green), b(blue), a(alpha) {}

	byte& operator[](int index)
	{
		switch (index)
		{
		default: return r;
		case 0:  return r;
		case 1:  return g;
		case 2:  return b;
		case 3:  return a;
		}
	}

	static size_t Size() { return 4; }

	Pixel()
	{
		r = 0; g = 0; b = 0; a = 0;
	}

};


class Image
{
public:
	Image(int width, int height, std::vector<Pixel> pixels);
	Image(std::string filePath);
	void Save(const std::string path);
	void FlipVertically();
	void FlipAndSave(const std::string path);
	void Invert();

	std::vector<Pixel> pixels;
	int width;
	int height;
	bool hasAlpha;
private:
	bool pixelsInitialized;
	inline Pixel* PixelAt(int x, int y);
	inline void Swap(Pixel* a, Pixel* b);
};

#endif