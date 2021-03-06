#include <opencv2/opencv.hpp>

#define RS 150	//赤閾値始め
#define RE 180	//赤閾値終わり
#define BS 90	//青閾値始め
#define BE 110	//青閾値終わり
#define GS 40	//緑閾値始め
#define GE 80	//緑閾値終わり
#define YS 10	//黄色閾値始め
#define YE 60	//黄色閾値終わり

using namespace cv;

int main(int argc, char *argv[]) {

	Mat img = imread("input.jpg");
	Mat hsv, r;
	const int h = img.rows;	//height
	const int w = img.cols;	//width

	namedWindow("result", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);

	while (1) {
		// 画像をRGBからHSVに変換
		cvtColor(img, hsv, CV_BGR2HSV);
		//閾値を設定しrにマスクとして格納
		inRange(hsv, Scalar(BS, 70, 70), Scalar(BE, 255, 255), r);

		imshow("result", r);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}
