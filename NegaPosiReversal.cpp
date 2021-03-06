#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[]) {

	Mat src_img = cv::imread("input.jpg");
	if (src_img.empty()) return -1;

	// NOT演算
	Mat dst_img = ~src_img;
	
	namedWindow("result", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("result", dst_img);
	
	waitKey(0);
	return 0;
}
