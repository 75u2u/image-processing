#include "opencv2/opencv.hpp"
int main()
{
	cv::VideoCapture cap(0);//デバイスのオープン
	//cap.open(0);//こっちでも良い．

	if (!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
	{
		//読み込みに失敗したときの処理
		return -1;
	}

	while (1)//無限ループ
	{
		cv::Mat frame;
		cap >> frame; // get a new frame from camera

		//
		//取得したフレーム画像に対して，クレースケール変換や2値化などの処理を書き込む．
		//

		cv::imshow("カメラをきどうちゅー", frame);//画像を表示．

		int key = cv::waitKey(1);
		if (key == 113)//qボタンが押されたとき
		{
			break;//whileループから抜ける．
		}
		else if (key == 115)//sが押されたとき
		{
			//フレーム画像を保存する．
			cv::imwrite("撮った奴.png", frame);
		}
	}
	cv::destroyAllWindows();
	return 0;
}