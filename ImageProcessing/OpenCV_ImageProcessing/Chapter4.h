#pragma once
#pragma region 第四章图像分割
#include "pch.h"
#include <math.h>
#include "opencv2/imgproc/imgproc.hpp"
#define PI 3.141156
class Chapter4
{
private:
	static Mat dst;
	static Mat img;
	static Mat imgSRC;
	static int Control;
	static bool ControlLine;
public:
	//哈夫变换
	static Mat& HoughW(Mat&);
	
	static Mat& Harr(Mat&);
	//控制窗口回调函数
	static void On_threshold(int,void*);
	//buton回调
	static void On_ClickButton(int,void*);
};
Mat Chapter4::dst = Mat::zeros(Size(50,50),CV_8UC1);
Mat Chapter4::img = Mat::zeros(Size(50,50),CV_8UC1);
Mat Chapter4::imgSRC = Mat::zeros(Size(50,50),CV_8UC1);
int Chapter4::Control = 0;
bool Chapter4::ControlLine = false;
//直线的检测
//x	cos a + y sin a = r
Mat& Chapter4::HoughW(Mat &src){
	//行列信息
	int cols = src.cols;
	int rows = src.rows;
	float a = 0,r = 0;
	float MaxR = sqrt(pow(cols,2)+pow(rows,2));
	cout<<MaxR<<endl;
	
	Mat src1 = Mat::zeros(Size(src.rows*1.5,src.cols*1.5),CV_8UC1);
	int rindex = 0;
	imshow("哈夫变换原图",src);
	Mat _sobel_x_src,_sobel_y_src;
	Sobel(src,_sobel_x_src,CV_16SC1,1,0);
	convertScaleAbs(_sobel_x_src,_sobel_x_src);
	Sobel(src,_sobel_y_src,CV_16SC1,0,1);
	convertScaleAbs(_sobel_y_src,_sobel_y_src);
	addWeighted(_sobel_x_src,0.5,_sobel_y_src,0.5,0,src);
	//Canny(src,src,0,255);

	imshow("边缘提取",src);
	//cout<<src<<endl;
	int num = 0;
	for (size_t x = 0; x < cols; x++)
	{
		for (size_t y = 0; y < rows; y++)
		{
			if(src.at<char>(y,x)>0){
				num++;
				for (size_t k = 0; k < src1.rows; k++)
				{
					a = (float)k / src1.rows * 2.0f * PI;
					//cout<<a<<",";
					r = x * cos(a) + y * sin(a)+src1.cols;
					rindex = r / (MaxR+src1.cols) * src1.cols * 0.4f;
					//if(rindex > 0)
					src1.at<uchar>(k,rindex) +=1;
				}
				//cout<<endl;
			}	
		}
		
	 }
	cout<<num<<endl;
	//cout<<src1<<endl;
	src1.convertTo(img,CV_8UC1);
	imshow("未经直方图均衡化过的哈夫变换",img);
	imgSRC = img.clone();
	//equalizeHist(img,img);
	//Mat dst1;
	equalizeHist(img,img);
	// try
	// {
	// 	Mat temp(Size(5,5), img.type());
	// 	for (size_t i = 0; i < img.rows - 2; i++)
	// 	{
	// 		for (size_t j = 0; j < img.cols - 2; j++)
	// 		{
	// 			for (int x = 0; x < 5; x++)
	// 			{
	// 				for (int y = 0; y < 5; y++)
	// 				{
	// 					temp.at<uchar>(x, y) = img.at<uchar>(i + x, j + y);
	// 				}
	// 			}
	// 			equalizeHist(temp, temp);
	// 			img.at<uchar>(i + 2, j + 2) = temp.at<uchar>(2, 2);
	// 		}
			
	// 	}
	// }
	// catch(const cv::Exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	

	
	
	imshow("局部直方图均衡化过的哈夫变换",img);	
	//imshow("全局直方图均衡化过的哈夫变换",dst1);	
	//阈值化
	//threshold(src1,src1,120,255,THRESH_BINARY);
	Control = 0;
	namedWindow("哈夫变换阈值化",WINDOW_AUTOSIZE);
	createTrackbar("阈值","哈夫变换阈值化",&Control,255,On_threshold);
	int ANS = 0;
	createTrackbar("寻找线","哈夫变换阈值化",&ANS,1,On_ClickButton);
	On_threshold(0,0);
	// //cout<<src1<<endl;  
	// imshow("哈夫变换原图",src);
	
	


}
Mat& Chapter4::Harr(Mat &src){
	//行列信息
	int cols = src.cols;
	int rows = src.rows;



}
void Chapter4::On_threshold(int, void *){
	
	threshold(img,dst,Control,255,0);
	imshow("哈夫变换阈值化",dst);
	Mat src1 = imgSRC.clone();
	Mat roi = src1(Rect(0,0,dst.cols,dst.rows));
	src1.copyTo(roi,dst);
	imshow("imgsrc",imgSRC);
	imshow("叠加",src1);
	vector<Point2i> points;
	if(ControlLine){
		// for (size_t i = 0; i < dst.; i++)
		// {
		// 	/* code */
		// }
		
	}
}
void Chapter4::On_ClickButton(int, void *){
	if(ControlLine){
		ControlLine = false;
	}
	else
	{
		ControlLine = true;
	}
	
}
#pragma endregion