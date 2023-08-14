#pragma once
#include <string>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <opencv2/opencv.hpp>

struct begin
{
public:
	void run();
	void sayHello();
	void loading();
};

class solution
{
private:
	std::string directory;
public:
	solution() : directory("E:\\VS projects\\OpenCV_Test_1\\naruto.jpg") {}
	int ImageToASCII();
	int calculateAVG(cv::Mat img, int rox, int colx, int scalr);
};
