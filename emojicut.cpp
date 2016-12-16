#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){

	std::string inname;
	std::cout << "filename:";
	if (argc <= 1){
		std::getline(std::cin,inname);
	}
	else{
		inname = argv[1];
		std::cout << inname << std::endl;
	}
	cv::Mat img = cv::imread(inname);
	cv::Mat emoji;
	int y = 0, x = 0;
	std::string front, end;
	std::cout << "front:";
	std::getline(std::cin,front);
	std::cout << "end:";
	std::getline(std::cin, end);

	while (1){
		cv::Mat tmp(img,cv::Rect(x*128,y*128,128,128));
		tmp.copyTo(emoji);
		cv::imshow("emoji", emoji);
		cv::waitKey(1);
		std::string outname;
		std::cout << "filename(q:quit):";
		std::getline(std::cin,outname);
		if (outname == "q")break;
		cv::imwrite(front + outname + end, emoji);
		x++;
		if (x * 128 + 127 >= img.cols){
			x = 0;
			y++;
		}
		if (y * 128 + 127 >= img.rows)break;
	}

	return 0;
}