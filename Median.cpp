#include "opencv2/opencv.hpp"

using namespace cv;

int main(void)
{
	Mat im = imread("sparrow.png");    // 画像の取得
	medianBlur(im, im, 7);          // メディアンフィルタ
	imshow("Show image", im);       // 画像の表示
	waitKey(0);                     // 入力待機
	return 0;
}
