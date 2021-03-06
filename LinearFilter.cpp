#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char* argv[])
{
	int hr = -1;
	try
	{
		Mat src, dst;
		src = imread("input.jpg", IMREAD_COLOR);

		// 3 x 3 のマスクを作成する。
		Mat kernel = (Mat_<float>(3, 3) <<
			0.11, 0.11, 0.11,
			0.11, 0.11, 0.11,
			0.11, 0.11, 0.11); //平滑化フィルタ

		filter2D(src, dst, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT); //画像の畳み込み

		cout << "Successed" << endl;
		imshow("result", dst);
		waitKey(0);
		hr = 0;
	}
	catch (Exception ex)
	{
		cout << ex.err << endl;
	}
	return hr;
}
