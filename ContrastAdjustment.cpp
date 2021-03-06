#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
	// 画像の取得
	Mat img = imread("input.jpg");
	// 出力画像
	Mat result;
	// ルックアップテーブル作成
	// 入力パラメータ
	float a = 20.0;
	uchar lut[256];
	for (int i = 0; i < 256; i++)
		//シグモイド関数
		lut[i] = 255.0 / (1 + exp(-a * (i - 128) / 255));

	 // 輝度値の置き換え処理
	LUT(img, Mat(Size(256, 1), CV_8U, lut), result);
	
	// 結果画像の表示
	namedWindow("result", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("result", result);

	waitKey(0);
	return 0;
}
