// Image rng.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers/Image.h"
#include <random>
#include <chrono>

using namespace std;

void testRng()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 255); // distribution in range [1, 6]



	int n = 0;

	auto Start = std::chrono::high_resolution_clock::now();
	while (true)
	{
		int a = dist6(rng);
		n++;
		auto End = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> Elapsed = End - Start;
		if (Elapsed.count() >= 1000.0)
			break;
	}
	cout << n;
}



int main()
{




    Image image("in.png");
    
	vector<vector<vector<int>>> randImage;
	for (int j = 0; j < image.width; j++)
	{
		for (int i = 0; i < image.height; i++)
		{
			Pixel data = image.pixels[j + image.width * i];
			data.r = (int(data.r) + 255) > 255 ? 255 : data.r + 255;


			image.pixels[j + image.width * i] = data;
			//(*image.pixels)[j + image.width * i].a += 255;
		}
	}

	image.Save("out.png");


    std::cout << "Hello World!\n";
}
