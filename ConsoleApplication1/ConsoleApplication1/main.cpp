// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;



int main()
{
	int Stop = 0;		//A very gentle variable.
	int videoStatus = 0;

	ofstream myfile;
	myfile.open("OverHere.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();



	namedWindow("Video", WINDOW_AUTOSIZE);
	namedWindow("Photo", WINDOW_AUTOSIZE);
	namedWindow("PhotoOut", WINDOW_AUTOSIZE);



	VideoCapture cap;
	//videoStatus = cap.open("../CuteCat.mp4");
	videoStatus = cap.open(0);

	
	Mat frame;
	Mat frameOut;
	Mat Photo = imread("Chat.JPG");
	Mat PhotoOut;
	imshow("Photo", Photo);

	GaussianBlur(Photo, PhotoOut, Size(5, 5), 3, 3);

	imshow("PhotoOut", PhotoOut);

	for (;;)
	{
		cap >> frame;
		if (frame.empty()) { break; }
		GaussianBlur(frame, frame, Size(5, 5), 3, 3);
		cvtColor(frame, frameOut, COLOR_BGR2GRAY);
		Sobel(frameOut, frameOut, -1, 1, 0, 3);
		imshow("Video", frameOut);
		if (waitKey(30) >= 0) break;
	}


	destroyWindow("Photo");
	destroyWindow("PhotoOut");
	destroyWindow("Video");

	cout << "HELP ME" << endl;
    return 0;
}

