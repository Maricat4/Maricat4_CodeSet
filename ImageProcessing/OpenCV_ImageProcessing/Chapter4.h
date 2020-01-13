#pragma once
#include "pch.h"
using namespace cv;
using namespace std;
class Chapter4
{
public:
    //傅里叶变换
    static void FourierTransform(const string &);
	//傅里叶变换
	static void FourierTransform1(const string &);
	
private:
	//重排频谱图
	static void ReSet(const Mat &,Mat &);
	//傅里叶反变换
	static void iFouierTransform(const Mat&,Mat &);
	//理想低通滤波器
};

void Chapter4::FourierTransform(const string &str){
	Mat src = imread(str,0);
	imshow("原图",src);
	
	//copyMakeBorder(src, src, 0, src.rows, 0, src.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat pad = Mat_<float>(src);
	//Mat _complex;

	
	Mat _man;
	Mat planes[] = {Mat_<float>(pad), Mat::zeros(pad.size(), CV_32F)};          // Mat 数组，第一个为扩展后的图像，一个为空图像，
    Mat _complex = Mat(src.size(),CV_32FC2);                                                                                                    
    merge(planes, 2, _complex);  
	cout<<_complex.type()<<","<<CV_32FC2<<endl;
	dft(_complex,_complex);
	Mat _c(_complex, Rect(0, 0, 5, 5));
	cout<<_c<<endl;
	cout<<_c.type()<<","<<CV_32FC1<<","<<_complex.type()<<","<<CV_32FC2<<endl;
	split(_complex,planes);
	magnitude(planes[0],planes[1],planes[0]);
		
	_man = planes[0];
	_man+=Scalar::all(1);
	log(_man,_man);
	normalize(_man,_man,0, 1,CV_MINMAX);

	 _man = _man(Rect(0, 0, _man.cols & -2, _man.rows & -2)); 
 
    int cx = _man.cols/2;
    int cy = _man.rows/2;
 
    // rearrange the quadrants of Fourier image 
	//对傅立叶变换的图像进行重排，4个区块，从左到右，从上到下 分别为q0, q1, q2, q3
    // so that the origin is at the image center                                                          
	//  对调q0和q3, q1和q2
    Mat tmp;
    Mat q0(_man, Rect(0, 0, cx, cy));
    Mat q1(_man, Rect(cx, 0, cx, cy));
    Mat q2(_man, Rect(0, cy, cx, cy));
    Mat q3(_man, Rect(cx, cy, cx, cy));
	
  	q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
 
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);


	imshow("频谱图",_man);

	

}

void Chapter4::FourierTransform1(const string &str0){
	Mat _m1 = imread(str0,0);
	imshow("源图像",_m1);
	_m1.convertTo(_m1,CV_32F);
	Mat planes[] = {Mat_<float>(_m1), Mat::zeros(_m1.size(), CV_32F)}; 

	Mat _m2 = Mat(_m1.size(),CV_32FC2);
	merge(planes,2,_m2);
	dft(_m2,_m2);
	
	split(_m2,planes);
	magnitude(planes[0],planes[1],planes[0]);

	Mat _m3 = planes[0];
	_m3+=Scalar::all(1);
	log(_m3,_m3);
	normalize(_m3,_m3,0, 1,CV_MINMAX);

	Mat _m4;
	ReSet(_m3,_m4);
	imshow("频率谱",_m4);

	threshold(_m4,_m4,0.3,1,THRESH_TOZERO);
	imshow("频率谱1",_m4);
	//pow()
	//Mat _m5;
	//iFouierTransform(_m2,_m5);
	//imshow("复原图",_m5);
}

void Chapter4::ReSet(const Mat &a,Mat &b){
	a.copyTo(b);
	int cx = b.cols/2;
    int cy = b.rows/2;
    Mat q0(b, Rect(0, 0, cx, cy));
    Mat q1(b, Rect(cx, 0, cx, cy));
    Mat q2(b, Rect(0, cy, cx, cy));
    Mat q3(b, Rect(cx, cy, cx, cy));
	Mat tmp;
  	q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

void Chapter4::iFouierTransform(const Mat &a,Mat &b){
	//--------------------------------------------------------------------------
	//dft变换后利用idft变换恢复原图像，显示效果与原图像相差无几，
	Mat frequencyImg;
	a.copyTo(frequencyImg);
	Mat iDft[] = {Mat::zeros(a.size(),CV_32F),Mat::zeros(a.size(),CV_32F)};
	idft(frequencyImg,frequencyImg);
	split(frequencyImg,iDft);
	magnitude(iDft[0],iDft[1],iDft[0]);
	normalize(iDft[0],iDft[0],1,0,CV_MINMAX);
	iDft[0].copyTo(b);
}