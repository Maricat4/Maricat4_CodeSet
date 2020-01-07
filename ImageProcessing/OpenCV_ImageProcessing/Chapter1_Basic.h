#pragma once
#include "pch.h"
class Chapter1_Basic
{
public:
	struct Node
	{
		int x;
		int y;
	};
	Chapter1_Basic();
	~Chapter1_Basic();
	//?????????????
	//????С??????????????????б??????????
	//
	static void ResizeImg(std::string s1,float x,float y);
	// ????????α任
	static void NonLinearTransform(std::string src);
	// Voronoi?
	static void Voronoi(std::string src);
	static Node minNode(Node C[20], Node test);
	// ?????	
	static void ResizeJ(const std::string &src);
};


#include "pch.h"
#include "Chapter1_Basic.h"
#include <map>

Chapter1_Basic::Chapter1_Basic()
{
}


Chapter1_Basic::~Chapter1_Basic()
{
}


void Chapter1_Basic::ResizeImg(string s1,float x,float y)
{
	Mat src = imread(s1);
	Mat dst(src.size().width*x, src.size().height*y,src.type());
	imshow("原始图像", src);
	resize(src, dst, dst.size(), x, y, 0);
	imshow("最近邻插值", dst);
	resize(src, dst, dst.size(), x, y, 1);
	imshow("双线性插值", dst);
	resize(src, dst, dst.size(), x, y, 2);
	imshow("双三次插值", dst);
	// TODO: 在此处添加实现代码.
}


// 非线性几何变换
void Chapter1_Basic::NonLinearTransform(string s1)
{
	Mat src = imread(s1, 0);
	Mat dst = Mat::zeros(src.size(), CV_8SC1);
	imshow("原图像",src);
	for (int i = src.rows / 2; i < src.rows; i++)
	{
		for (int j = src.cols / 2; j < src.cols; j++)
		{
			
		}
	}
}


// Voronoi图
void Chapter1_Basic::Voronoi(string src)
{
	Mat A = imread(src, 1);
	Mat B = A.clone();
	imshow("原图像", A);
	//map<Node, Scalar> mapColor;
	int count = 1000;
	Node nodeC[1000];
	Node temp;
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
	{
		nodeC[i].x = rand() % A.rows;
		nodeC[i].y = A.cols-1-rand() % A.cols;
	}
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			temp.x = i;
			temp.y = j;
			temp = minNode(nodeC, temp);
			B.at<Vec3b>(i, j) = A.at<Vec3b>(temp.x,temp.y);
		}
	}
	imshow("Voronoi图", B);

	cout << A.rows*A.cols;
}


// Voronoi
Chapter1_Basic::Node Chapter1_Basic::minNode(Chapter1_Basic::Node C[20], Chapter1_Basic::Node test)
{
	// TODO: 在此处添加实现代码.
	int min = 0x7fffffff;
	int t = 0;
	int index = 0;
	Chapter1_Basic::Node ans;
	for (int i = 0; i < 1000; i++)
	{
		t = pow(test.x - C[i].x, 2) + pow(test.y - C[i].y, 2);
		if (min > t)
		{
			min = t;
			index = i;
		}
	}
	ans.x = C[index].x;
	ans.y = C[index].y;
	return ans;
}


// 杰尼龟
void Chapter1_Basic::ResizeJ(const std::string &src)
{
	// TODO: 在此处添加实现代码.
	Mat	A = imread(src);
	imshow("杰尼龟",A);
	cout << "行：" << A.rows<<endl;
	cout <<"列："<< A.cols << endl;
	cout <<"图像类型"<< A.type() << endl;
	
	/*boxFilter(A, A, 24, Size(15, 15));
	imshow("平滑杰尼龟", A);
	vector<Mat> m;
	split(A, m);
	imshow("B", m[0]);
	imshow("G", m[1]);
	imshow("R", m[2]);
	equalizeHist(m[0], m[0]);
	equalizeHist(m[1], m[1]);
	equalizeHist(m[2], m[2]);
	imshow("B1", m[0]);
	imshow("G1", m[1]);
	imshow("R1", m[2]);

	merge(m, A);
	imshow("平滑杰尼龟1", A);*/
	resize(A, A, Size(1080, 1080), 0, 0, 2);
	imshow("平滑杰尼龟2", A);
	//for (int i = 0; i < 3; i++)
	//{
	//	Mat bgr(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
	//	Mat temp(img.rows, img.cols, CV_8UC1);
	//	Mat out[] = { bgr };
	//	int from_to[] = { i,i };
	//	mixChannels(&img, 1, out, 1, from_to, 1);
	//	//获得其中一个通道的数据进行分析
	//	imshow("1 channel", bgr);
	//	waitKey();
	//}
	/*equalizeHist(A, A);
	imshow("均衡平滑杰尼龟", A);*/

	/*Mat dst,dst1;
	Sobel(A, dst, CV_16SC4, 1, 0);
	convertScaleAbs(dst, dst);
	imshow("Sobel_x图像", dst);
	Sobel(A, dst1, CV_16SC4, 0, 1);
	convertScaleAbs(dst1, dst1);
	imshow("Sobel_y原图像", dst1);

	addWeighted(dst, 0.5, dst1, 0.5, 0, dst);
	imshow("Sobel_(x+y)原图像", dst);*/
}


