#pragma once
#include "pch.h"
using namespace cv;
using namespace std;
class Chapter4
{
public:
    //����Ҷ�任
    static void FourierTransform(const string &);
};

void Chapter4::FourierTransform(const string &str){
	Mat src = imread(str,0);
	imshow("ԭͼ",src);
	
	//copyMakeBorder(src, src, 0, src.rows, 0, src.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat pad = Mat_<float>(src);
	//Mat _complex;

	
	Mat _man;
	Mat planes[] = {Mat_<float>(pad), Mat::zeros(pad.size(), CV_32F)};          // Mat ���飬��һ��Ϊ��չ���ͼ��һ��Ϊ��ͼ��
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

	 _man = _man(Rect(0, 0, _man.cols & -2, _man.rows & -2));                                        //��֤ż���ı߳�
 
    int cx = _man.cols/2;
    int cy = _man.rows/2;
 
    // rearrange the quadrants of Fourier image 
	//�Ը���Ҷ�任��ͼ��������ţ�4�����飬�����ң����ϵ��� �ֱ�Ϊq0, q1, q2, q3
    // so that the origin is at the image center                                                          
	//  �Ե�q0��q3, q1��q2
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


	imshow("Ƶ��ͼ",_man);

	

}