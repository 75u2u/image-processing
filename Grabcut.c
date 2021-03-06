#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
	// Open another image
	Mat image;
	image = cv::imread("input.jpg");

	// define bounding rectangle 
	Rect rectangle(50, 70, image.cols - 150, image.rows - 180);

	Mat result;				// segmentation result (4 possible values)
	Mat bgModel, fgModel;	// the models (internally used)

	// GrabCut segmentation
	grabCut(image,			// input image
		result,				// segmentation result
		rectangle,			// rectangle containing foreground 
		bgModel, fgModel,	// models
		1,					// number of iterations
		GC_INIT_WITH_RECT); // use rectangle
	cout << "じょうずにやけました～" << endl;
	// Get the pixels marked as likely foreground
	compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
	// Generate output image
	Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
	image.copyTo(foreground, result); // bg pixels not copied

	// draw rectangle on original image
	cv::rectangle(image, rectangle, cv::Scalar(255, 255, 255), 1);
	namedWindow("Image");
	imshow("Image", image);

	// display result
	namedWindow("Segmented Image");
	imshow("Segmented Image", foreground);


	waitKey();
	return 0;
}