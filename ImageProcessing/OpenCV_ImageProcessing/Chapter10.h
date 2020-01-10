#pragma once
#pragma region ��10��ͼ��ָ�
#include "pch.h"
#include <math.h>
#include "opencv2/imgproc/imgproc.hpp"
#define PI 3.141156
class Chapter10
{
private:
	static Mat dst;
	static Mat img;
	static Mat imgSRC;
	static int Control;
	static bool ControlLine;
public:
	//����任
	static Mat& HoughW(Mat&);
	
	static Mat& Harr(Mat&);
	//���ƴ��ڻص�����
	static void On_threshold(int,void*);
	//buton�ص�
	static void On_ClickButton(int,void*);
};
Mat Chapter10::dst = Mat::zeros(Size(50,50),CV_8UC1);
Mat Chapter10::img = Mat::zeros(Size(50,50),CV_8UC1);
Mat Chapter10::imgSRC = Mat::zeros(Size(50,50),CV_8UC1);
int Chapter10::Control = 0;
bool Chapter10::ControlLine = false;
//ֱ�ߵļ��
//x	cos a + y sin a = r
Mat& Chapter10::HoughW(Mat &src){
	//������Ϣ
	int cols = src.cols;
	int rows = src.rows;
	float a = 0,r = 0;
	float MaxR = sqrt(pow(cols,2)+pow(rows,2));
	cout<<MaxR<<endl;
	
	Mat src1 = Mat::zeros(Size(src.rows*1.5,src.cols*1.5),CV_8UC1);
	int rindex = 0;
	imshow("����任ԭͼ",src);
	Mat _sobel_x_src,_sobel_y_src;
	Sobel(src,_sobel_x_src,CV_16SC1,1,0);
	convertScaleAbs(_sobel_x_src,_sobel_x_src);
	Sobel(src,_sobel_y_src,CV_16SC1,0,1);
	convertScaleAbs(_sobel_y_src,_sobel_y_src);
	addWeighted(_sobel_x_src,0.5,_sobel_y_src,0.5,0,src);
	//Canny(src,src,0,255);

	imshow("��Ե��ȡ",src);
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
	imshow("δ��ֱ��ͼ���⻯���Ĺ���任",img);
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
	

	
	
	imshow("�ֲ�ֱ��ͼ���⻯���Ĺ���任",img);	
	//imshow("ȫ��ֱ��ͼ���⻯���Ĺ���任",dst1);	
	//��ֵ��
	//threshold(src1,src1,120,255,THRESH_BINARY);
	Control = 0;
	namedWindow("����任��ֵ��",WINDOW_AUTOSIZE);
	createTrackbar("��ֵ","����任��ֵ��",&Control,255,On_threshold);
	int ANS = 0;
	createTrackbar("Ѱ����","����任��ֵ��",&ANS,1,On_ClickButton);
	On_threshold(0,0);
	// //cout<<src1<<endl;  
	// imshow("����任ԭͼ",src);
	
	


}
Mat& Chapter10::Harr(Mat &src){
	//������Ϣ
	int cols = src.cols;
	int rows = src.rows;



}
void Chapter10::On_threshold(int, void *){
	
	threshold(img,dst,Control,255,0);
	imshow("����任��ֵ��",dst);
	Mat src1 = imgSRC.clone();
	Mat roi = src1(Rect(0,0,dst.cols,dst.rows));
	src1.copyTo(roi,dst);
	imshow("imgsrc",imgSRC);
	imshow("����",src1);
	vector<Point2i> points;
	if(ControlLine){
		// for (size_t i = 0; i < dst.; i++)
		// {
		// 	/* code */
		// }
		
	}
}
void Chapter10::On_ClickButton(int, void *){
	if(ControlLine){
		ControlLine = false;
	}
	else
	{
		ControlLine = true;
	}
	
}
#pragma endregion