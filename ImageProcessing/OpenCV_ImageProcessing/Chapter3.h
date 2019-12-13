#pragma once
#include "pch.h"

class Chapter3
{
public:
	Chapter3();
	~Chapter3();

	// 图像的灰度变换
	static void GrayTransform(std::string src);
	// 分段线性变换函数
	static void SegmentationGrayTrans(std::string src);
	// 灰度级分层
	static void GrayScaleLayering(std::string filename);
	// 比特平面分层
	static void BitPlaneLayering(std::string filename);
	// 判断灰度级分层
	static bool BitLevelJudge(uchar gray, int layer);
	// 直方图均衡化
	static void HistogramEqualization(std::string filename);
	// 显示图像的直方图
	static void VisualizationHist(std::string filename);
	// 为Mat画灰度图，必须是单通道灰度图才可以
	static void VisualizationHistForMat(cv::Mat mat,std::string windowname);
	// 直方图匹配（直方图规定化）
	static void HistogramMatching(std::string filename1,std::string filename2);
	// 局部直方图处理
	static void LocalHistogramEqualization(std::string filename);
	// 使用直方图统计局部增强
	static void HistogramStatistics(std::string filename);
	// 计算Mat的均值与方差
	static void CalcMeanAndVariance(cv::Mat A, double& mean, double& Variance);
	// 平滑滤波器
	static void SmoothingFilter(std::string filename,std::string filename1);
	// 自己编写的滤波器代码段
	static void SmoothingFilterByOwn(cv::Mat A, cv::Mat &dst, cv::Size ksize);
	// 统计排序滤波器-中值滤波
	static void MedianFilter(std::string filename);
	// 锐化滤波器-拉普拉斯算子
	static void SharpeningFilterLaplaceOperator(std::string filename);
	// 拉普拉斯算子
	static void LaplaceOperator(cv::Mat A, cv::Mat &dst, cv::Mat &dst1);
	// 非锐化滤波以及高提升滤波
	static void NonShrpeningAndHighBoost(std::string filename);
	// Sobel算子
	static void SobelOperator();
	// 锐化滤波器-Sobel算子
	static void SharpeningFilterSobelOperator(std::string filename);
	// 混合空间增强
	static void CombiningSpatialEnhancement(std::string filename);
};

#include "Chapter3.h"
#include "pch.h"
using namespace cv;
using namespace std;
Chapter3::Chapter3()
{
}


Chapter3::~Chapter3()
{
}


// 图像的灰度变换,图像反转，对数变换，伽马变换
void Chapter3::GrayTransform(std::string src)
{
	Mat Src = imread(src);// TODO: 在此处添加实现代码.
	Mat Src1;
	Mat Src_1(Src.size(), CV_8UC1, Scalar(0));
	Mat Src_2(Src.size(), CV_8UC1, Scalar(0));
	Mat Src_3(Src.size(), CV_8UC1, Scalar(0));
	cvtColor(Src, Src1, CV_BGR2GRAY);
	imshow("原始图像", Src);
	if (Src1.type() == 0 && Src1.channels() == 1) {
		for (int i = 0; i < Src1.rows; i++)
		{
			for (int j = 0; j < Src1.cols; j++)
			{
				Src_1.at<uchar>(i, j) = 255 - Src1.at<uchar>(i, j);
				Src_2.at<uchar>(i, j) = log(1+ Src1.at<uchar>(i, j)) / log(1+255) * 255;
				Src_3.at<uchar>(i, j) = pow(Src1.at<uchar>(i, j),3) / pow(255,3) * 255;
			}
		}
		imshow("反转后的图像", Src_1);
		imshow("对数变换后的图像", Src_2);
		imshow("伽马变换后的图像", Src_3);
	}
	else {
		cout << "非灰度图";
	}
	
	
}


// 分段线性变换函数
void Chapter3::SegmentationGrayTrans(std::string src)
{
	// TODO: 在此处添加实现代码.
	Mat A= imread(src,0);
	Mat Src,Src1;
	if (A.channels() == 3)
		cvtColor(A, Src, CV_BGR2GRAY);
	else Src = A.clone();
	Src1 = Src.clone();
	imshow("原始图像",Src);
	uchar min = 255;
	uchar max = 0;
	uchar aver;
	float average = 0;
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if (min > Src.at<uchar>(i, j)) min = Src.at<uchar>(i, j);
			if (max < Src.at<uchar>(i, j)) max = Src.at<uchar>(i, j);
			average += (float) Src.at<uchar>(i, j)/(Src.rows * Src.cols);
		}
	}
	cout << "最小灰度值"<< (int)min<<endl;
	cout << "最大灰度值"<< (int)max<<endl;
	aver = (uchar)average;
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if(Src.at<uchar>(i, j)>=min && Src.at<uchar>(i, j) <= max)
			//值得注意的地方
			//Src.at<uchar>(i, j) = (((float)255 / (max - min)) * Src.at<uchar>(i, j) + (float)255 * min / (min - max));
			Src.at<uchar>(i, j) = 255 / (max - min) * (Src.at<uchar>(i, j)-min);
			else Src.at<uchar>(i, j) = 0;
			if (Src1.at<uchar>(i, j) >= aver)  Src1.at<uchar>(i, j) = 255;
			else Src1.at<uchar>(i, j) = 0;
		}
	}
	imshow("对比度拉伸后的图像",Src);
	imshow("阈值处理后的图像", Src1);
}


// 灰度级分层
void Chapter3::GrayScaleLayering(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat Src = imread(filename, 0);
	Mat Src1 = Src.clone();
	imshow("原图像",Src);
	uchar max = 0;
	float average = 0;
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			
			if (max < Src.at<uchar>(i, j)) max = Src.at<uchar>(i, j);
		}
	}
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if (Src.at<uchar>(i, j) >= max-75 && Src.at<uchar>(i, j) <= max)
			{
				Src.at<uchar>(i, j) = 255;
				Src1.at<uchar>(i, j) = 255;
			}	
			else {
				Src.at<uchar>(i, j) = 50;
				
			}	
		}
	}
	imshow("法一图像", Src);
	imshow("法二图像", Src1);
}


// 比特平面分层
void Chapter3::BitPlaneLayering(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat Src = imread(filename, 0);
	imshow("原图像", Src);
	Mat Src0[8],a,b,c;
	for (int i = 0; i < 8; i++)
	{
		Src0[i] = Src.clone();
	}
	a = Src.clone();
	b = Src.clone();
	c = Src.clone();
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			for (int index = 0; index < 8; index++)
			{
				
				if (BitLevelJudge(Src.at<uchar>(i, j), index))
					Src0[index].at<uchar>(i, j) = 255;
				else {
					Src0[index].at<uchar>(i, j) = 0;
				}
			}
			//利用比特平面重建图像
			a.at<uchar>(i, j) = Src0[6].at<uchar>(i, j)/255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
			b.at<uchar>(i, j) = Src0[5].at<uchar>(i, j) / 255 * 32 + Src0[6].at<uchar>(i, j) / 255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
			c.at<uchar>(i, j) = Src0[4].at<uchar>(i, j) / 255 * 16 + Src0[5].at<uchar>(i, j) / 255 * 32 + Src0[6].at<uchar>(i, j) / 255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
		}
	}
	//threshold(Src, Src8, 127, 255, CV_THRESH_BINARY);
	imshow("第1比特平面", Src0[0]);
	imshow("第2比特平面", Src0[1]);
	imshow("第3比特平面", Src0[2]);
	imshow("第4比特平面", Src0[3]);
	imshow("第5比特平面", Src0[4]);
	imshow("第6比特平面", Src0[5]);
	imshow("第7比特平面", Src0[6]);
	imshow("第8比特平面", Src0[7]);
	imshow("使用比特平面7,8重建", a);
	imshow("使用比特平面6,7,8重建", b);
	imshow("使用比特平面5,6,7,8重建", c);
}


// 判断灰度级分层
bool Chapter3::BitLevelJudge(uchar gray,int layer)
{
	// TODO: 在此处添加实现代码.
	switch (layer)
	{
	case 0:
		if((gray  & 0x01) == 0x01)

		return true;
		break;
	case 1:
		if ((gray & 0x02) == 0x02)
			return true;
		break;
	case 2:
		if ((gray & 0x04) == 0x04)
			return true;
		break;
	case 3:
		if ((gray & 0x08) == 0x08)
			return true;
		break;
	case 4:
		if ((gray & 0x10) == 0x10)
			return true;
		break;
	case 5:
		if ((gray & 0x20) == 0x20)
			return true;
		break;
	case 6:
		if ((gray & 0x40) == 0x40)
			return true;
		break;
	case 7:
		if ((gray & 0x80) == 0x80)
			return true;
		break;
	default:
		cout << "wrong layer";
		break;
	}
	return false;
}


// 直方图均衡化
void Chapter3::HistogramEqualization(std::string filename)
{
	// TODO: 在此处添加实现代码.
	//原图像
	Mat Src = imread(filename, 0);
	imshow("原图像", Src);
	VisualizationHistForMat(Src,"原图直方图");
	//映射后的像素灰度值
	float s;
	//最大灰度值
	int L = 256;
	//灰度级统计
	Mat hist;
	//映射函数
	int T[256];
	//像素统计
	float sum = 0;
	int MN = Src.size().area();
	//计算原图像像素的频率
	//灰度范围
	float range[] = { 0,256 };
	const float *histRanges = { range };
	calcHist(&Src, 1, 0, Mat(), hist, 1, &L, &histRanges, true, false);
	//计算映射函数
	for (int i = 0; i < L; i++)
	{
		sum += hist.at<float>(i);
		s = (float)(L - 1) / MN * sum;
		T[i] = (int)s;
	}
	Mat Src1 = Src.clone();
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			Src.at<uchar>(i, j) = T[Src.at<uchar>(i, j)];
		}
	}
	imshow("均衡后的图像", Src);
	VisualizationHistForMat(Src,"均衡后的直方图");
	
	equalizeHist(Src1, Src1);
	imshow("OpenCV_API均衡后的图像", Src1);
	VisualizationHistForMat(Src1, "OpenCV_API均衡后的直方图");
}


// 显示图像的直方图
void Chapter3::VisualizationHist(std::string filename)
{
	// TODO: 在此处添加实现代码.
	//源图像
	Mat Src = imread(filename, 0);
	//灰度
	imshow("原始图像", Src);
	//用稀疏
	Mat hist;

	int histSize = 256;
	//灰度范围
	float range[] = { 0,256 };
	const float *histRanges = { range };
	//图像高，宽以及小矩形的宽度
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = 2;
	//直方图灰度图 矩阵
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	//计算原图像像素的频率
	calcHist(&Src, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);
	Rect a;
	float height = 0;
	//画直方图矩形
	for (int i = 0; i < histSize; i++)
	{
		height = 10*hist_h * (hist.at<float>(i) / Src.size().area());
		a = Rect(Point(bin_w*i,400 -height) ,Size(bin_w-1, height));
		rectangle(histImage, a, Scalar(255, 255, 255));
	}
	imshow("直方图", histImage);
}



// 为Mat画灰度图，必须是单通道灰度图才可以
void Chapter3::VisualizationHistForMat(Mat mat,string windowname="NULL")
{
	// TODO: 在此处添加实现代码.
	//源图像
	Mat Src = mat;
	//显示原图
	//imshow("原始图像", Src);
	//用稀疏
	Mat hist;

	int histSize = 256;
	//灰度范围
	float range[] = { 0,256 };
	const float *histRanges = { range };
	//图像高，宽以及小矩形的宽度
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = 2;
	//直方图灰度图 矩阵
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	//计算原图像像素的频率
	calcHist(&Src, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);
	Rect a;
	float height = 0;
	//画直方图矩形
	for (int i = 0; i < histSize; i++)
	{
		height = 10 * hist_h * (hist.at<float>(i) / Src.size().area());
		a = Rect(Point(bin_w*i, 400 - height), Size(bin_w - 1, height));
		rectangle(histImage, a, Scalar(255, 255, 255));
	}
	if(windowname!="NULL")
	imshow(windowname, histImage);
}


// 直方图匹配（直方图规定化）
void Chapter3::HistogramMatching(std::string filename1, ::string filename2)
{
	// TODO: 在此处添加实现代码.
	Mat Src = imread(filename1, 0);
	Mat Target = imread(filename2, 0);
	imshow("原图像", Src);
	imshow("需要匹配的直方图图像", Target);
	VisualizationHistForMat(Src, "原图像的直方图");
	VisualizationHistForMat(Target, "需要匹配的直方图图像直方图");

	//第一步 直方图均衡化
	equalizeHist(Src, Src);
	Mat hist;
	//灰度范围
	float range[] = { 0,256 };
	const float *histRanges = { range };
	int histSize = 256;
	
	//Mat hist;
	calcHist(&Target, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);

	int sum = 0;
	float z;
	int MN = Target.size().area();
	int G[256];
	//计算映射函数
	for (int i = 0; i < histSize; i++)
	{
		sum += hist.at<float>(i);
		z = (float)(histSize - 1) / MN * sum;
		G[i] = (int)z;
	}

	int S[256] = {0};
	int min = 0;
	int tempk;
	int j = 0;
	for (int i = 0; i < histSize; i++)
	{
		min = abs(i - G[0]);
		tempk = j = 0;
		for (j = 0; j < histSize; j++)
		{
			if (min > abs(i - G[j])) {
				min = abs(i - G[j]);
				tempk = j;
			}
		}
		S[i] = tempk;
		cout << S[i] << endl;
	}
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			Src.at<uchar>(i, j) = S[Src.at<uchar>(i, j)];
		}
	}
	imshow("匹配后的图像", Src);
	VisualizationHistForMat(Src, "匹配后图像的直方图");
}


// 局部直方图处理
void Chapter3::LocalHistogramEqualization(string filename)
{
	// TODO: 在此处添加实现代码.
	Mat Src = imread(filename, 0);
	Mat Src_hist(Src.size(),Src.type());
	imshow( "原图像", Src);
	VisualizationHistForMat(Src,"原图像的灰度图");
	equalizeHist(Src, Src_hist);
	imshow("直方图均衡化图像", Src_hist);
	VisualizationHistForMat(Src_hist, "直方图均衡化图像的灰度图");
	
	Mat temp(Size(5,5), Src.type());
	for (int i = 0; i < Src.rows - 5; i++)
	{
		for (int j = 0; j < Src.cols - 5; j++)
		{
			for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					temp.at<uchar>(x, y) = Src.at<uchar>(i + x, j + y);
				}
			}
			equalizeHist(temp, temp);
			Src.at<uchar>(i + 2, j + 2) = temp.at<uchar>(2, 2);
			/*for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					Src.at<uchar>(i + x, j + y) = temp.at<uchar>(x, y);
				}
			}*/
		}
	}
	//return;
	imshow("局部直方图均衡化图像", Src);
	VisualizationHistForMat(Src, "局部直方图均衡化图像的灰度图");

}


// 使用直方图统计局部增强
void Chapter3::HistogramStatistics(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat Src = imread(filename, 0);
	Mat Src_hist;
	imshow("原图像", Src);
	VisualizationHistForMat(Src, "原图像直方图");
	equalizeHist(Src, Src_hist);
	imshow("全局直方图均衡", Src_hist);
	VisualizationHistForMat(Src_hist, "全局直方图均衡直方图");
	//全局平均灰度值以及全局灰度方差
	double m = 0,s2 = 0;
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			m += (double)Src.at<uchar>(i, j);
		}
		
	}
	m = m / Src.size().area();
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			s2 +=pow((double)Src.at<uchar>(i, j)-m,2);
		}	
	}
	s2 = s2 / Src.size().area();
	s2 = pow(s2,0.5);
	Mat Src1 = Src.clone();
	//遍历区域
	Mat temp(Size(3, 3), CV_8UC1);
	double  k1 = 0.02, k2 = 0.4, k0 = 0.4;
	int E = 4;
	double mean = 0, Variance = 0;
	for (int i = 1; i < Src.rows - 1; i++)
	{
		for (int j = 1; j < Src.cols - 1; j++)
		{
			for (int x = 0; x < temp.rows; x++)
			{
				for (int y = 0; y < temp.cols; y++)
				{
					temp.at<uchar>(x, y) = Src.at<uchar>(i - 1 + x, j - 1 + y);
				}
			}
			mean = 0;
			Variance = 0;
			//计算区域的均值与方差
			CalcMeanAndVariance(temp, mean, Variance);
			if (mean <= (k0 * m) && Variance >= (k1 * s2) && Variance <= (k2 * s2)) {
				Src1.at<uchar>(i, j) = E * Src.at<uchar>(i, j);
			}
			
		}
		
	}
	imshow("直方图统计增强", Src1);
	VisualizationHistForMat(Src1,"直方图统计增强直方图");
}


// 计算Mat的均值与方差
void Chapter3::CalcMeanAndVariance(cv::Mat A, double& mean, double& Variance)
{
	// TODO: 在此处添加实现代码.
	double sum = 0;
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			mean += A.at<uchar>(i, j);
		}
		/*mean += sum / A.size().area();
		sum = 0;*/
	}
	mean = mean / 9.0;
	//cout <<"均值：" <<mean<<endl;
	
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			Variance += pow(A.at<uchar>(i, j) - mean, 2);
		}
		/*Variance += sum / A.size().area();
		sum = 0;*/
	}
	Variance = Variance / 9.0;
	Variance = pow(Variance,0.5);
	//cout << "方差：" << Variance << endl;
	
}


// 平滑滤波器
void Chapter3::SmoothingFilter(std::string filename,std::string filename1)
{
	// TODO: 在此处添加实现代码.
	Mat src = imread(filename, 0);
	Mat src1 = imread(filename1, 0);
	imshow("原图像",src);
	Mat dst;
	boxFilter(src, dst,src.depth(),Size(3,3));
	imshow("3x3方形均值滤波原图像", dst);
	boxFilter(src, dst, src.depth(), Size(5, 5));
	imshow("5x5方形均值滤波原图像", dst);
	/*boxFilter(src, dst, src.depth(), Size(9, 9));
	imshow("9x9方形均值滤波原图像", dst);
	boxFilter(src, dst, src.depth(), Size(15, 15));
	imshow("15x15方形均值滤波原图像", dst);
	boxFilter(src, dst, src.depth(), Size(35, 35));
	imshow("35x35方形均值滤波原图像", dst);*/

	/*SmoothingFilterByOwn(src, dst, Size(3, 3));
	imshow("3x3方形均值滤波图像", dst);
	SmoothingFilterByOwn(src, dst, Size(5, 5));
	imshow("5x5方形均值滤波图像", dst);
	SmoothingFilterByOwn(src, dst, Size(9, 9));
	imshow("9x9方形均值滤波原图像", dst);
	SmoothingFilterByOwn(src, dst, Size(15, 15));
	imshow("15x15方形均值滤波原图像", dst);
	SmoothingFilterByOwn(src, dst, Size(35, 35));
	imshow("35x35方形均值滤波原图像", dst);*/
	imshow("哈勃望远镜图像", src1);
	boxFilter(src1, dst, src.depth(), Size(15, 15));
	imshow("哈勃望远镜15x15方形均值滤波后图像", dst);
	threshold(dst, dst, 70, 255, CV_THRESH_BINARY);
	imshow("阈值化的图像", dst);
}




// 自己编写的均值滤波器代码段
// 核为全1矩阵
void Chapter3::SmoothingFilterByOwn(cv::Mat A, cv::Mat &dst, cv::Size ksize = Size(3, 3))
{
	// TODO: 在此处添加实现代码.
	Mat kMat = Mat::ones(ksize, CV_8UC1);
	Mat b = Mat::zeros(Size(kMat.rows-1+A.rows, kMat.cols - 1 + A.cols), A.type());
	
	dst = A.clone();
	float a = 0;
	for (int i = 0; i < dst.rows - ksize.width; i++)
	{
		for (int j = 0; j < dst.cols - ksize.height; j++)
		{
			for (int x = 0; x < ksize.width; x++)
			{
				for (int y = 0; y < ksize.height; y++)
				{
					a += (kMat.at<uchar>(x, y)*A.at<uchar>(i + x, j + y));
				}
			}
			a = a / ksize.area();
			dst.at<uchar>(i + ksize.width / 2, j + ksize.height / 2) = a;
			a = 0;
		}
	}
}


// 统计排序滤波器-中值滤波-最小值滤波-最大值滤波
void Chapter3::MedianFilter(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat dst,src = imread(filename, 0);
	imshow("原图像", src);
	blur(src, dst, Size(3, 3));
	imshow("均值滤波图像", dst);
	medianBlur(src, dst, 3);
	imshow("中指滤波图像", dst);
}


// 锐化滤波器-拉普拉斯算子
void Chapter3::SharpeningFilterLaplaceOperator(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("原图像", src);
	Laplacian(src, dst, CV_16SC1,1,1,0,4);
	Mat src1(src.size(), CV_16SC1);
	for (int i = 0; i < src1.rows; i++)
	{
		for (int j = 0; j < src1.cols; j++)
		{
			src1.at<short>(i, j) = (short)src.at<uchar>(i, j);
		}
	}
	
	//imshow("拉普拉斯算子滤波后的图像1", dst);
	Mat dst2 = dst.clone();
	addWeighted(src1, 1, dst, 1, 0, dst);
	convertScaleAbs(dst, dst);
	imshow("拉普拉斯算子滤波后的混合图像00", dst);
	addWeighted(src1, 1, dst2, -1, 0, dst);
	convertScaleAbs(dst, dst);
	imshow("拉普拉斯算子滤波后的混合图像01", dst);
	LaplaceOperator(src, dst, dst1);
	//imshow("拉普拉斯算子滤波后图像", dst);
	//imshow("拉普拉斯算子(加对角线方向)滤波后图像", dst1);

	dst2 = dst.clone();
	//cout << dst2;
	addWeighted(src, 1, dst,  1, 0, dst);
	imshow("拉普拉斯算子滤波后的混合图像", dst);
	addWeighted(src, 1, dst2, -1, 0, dst);
	imshow("拉普拉斯算子滤波后的混合图像1", dst);
	dst2 = dst1.clone();
	addWeighted(src, 1, dst1, -1, 0, dst1);
	imshow("拉普拉斯算子(加对角线方向)滤波后的混合图像", dst1);
	addWeighted(src, 1, dst2, 1, 0, dst1);
	imshow("拉普拉斯算子(加对角线方向)滤波后的混合图像1", dst1);
}


// 拉普拉斯算子
void Chapter3::LaplaceOperator(cv::Mat A,cv::Mat &dst, cv::Mat &dst1)
{
	// TODO: 在此处添加实现代码.
	Mat la1,la2;
	la1 = (Mat_<short int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	la2 = (Mat_<short int>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
	Mat temp = Mat::zeros(A.size(),CV_16SC1);
	Mat temp1 = Mat::zeros(A.size(), CV_16SC1);
	Mat temp2 = Mat::zeros(A.size(), CV_8UC1);
	Mat temp3 = Mat::zeros(A.size(), CV_8UC1);
	dst = Mat::zeros(A.size(), CV_8UC1);
	dst1 = Mat::zeros(A.size(), CV_8UC1);
	
	short sum = 0, sum1 = 0, max = 0, max1 = 0, min = 0, min1 = 0, absmax = 0, absmax1 = 0;
	for (int i = 0; i < A.rows - 3; i++)
	{
		for (int j = 0; j < A.cols - 3; j++)
		{
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					sum += A.at<uchar>(i + x, j + y) * la1.at<short>(x, y);
					sum1 += A.at<uchar>(i + x, j + y) * la2.at<short>(x, y);
				}
			}
			max = max > sum ? max : sum;
			absmax = absmax > abs(sum) ? absmax : abs(sum);
			max1 = max1 >sum1 ? max1 : sum1;
			absmax1 = absmax1 > abs(sum1) ? absmax1 : abs(sum1);
			min = min < sum ? min : sum;
			min1 = min1 < sum1 ? min1 : sum1;
			temp.at<short>(i + 1, j + 1) = sum;
			temp1.at<short>(i + 1, j + 1) = sum1;
			sum = 0;
			sum1 = 0;
		}
	}
	float temp_;
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			temp_ = temp.at<short>(i, j) < 0 ? 0 : temp.at<short>(i, j);
			temp_ = (float)abs(temp_) / max * 255;
			dst.at<uchar>(i, j) = temp_;

			temp_ = (float)(temp.at<short>(i, j) - min) / (max - min) * 255;
			temp2.at<uchar>(i, j) = temp_;
			
			temp_ = temp1.at<short>(i, j) < 0 ? 0 : temp1.at<short>(i, j);
			temp_ = (float)abs(temp_) / max1 * 255;
			dst1.at<uchar>(i, j) = temp_;

			//标定后的图像
			temp_ = (float)(temp1.at<short>(i, j) - min1) / (max1 - min1) * 255;
			temp3.at<uchar>(i, j) = temp_;
		}
	}
	imshow("算子1标定图像", temp2);
	imshow("算子2标定图像", temp3);

}


// 非锐化滤波以及高提升滤波
void Chapter3::NonShrpeningAndHighBoost(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("原图像", src);
	GaussianBlur(src, dst, Size(5,5), 3);
	imshow("使用高斯滤波器模糊的结果",dst);
	addWeighted(src, 1, dst, -1, 0, dst);
	dst1 = dst.clone();
	for (int i = 0; i < dst.size().height; i++)
	{
		for (int j = 0; j < dst.size().width; j++)
		{
			dst1.at<uchar>(i, j) = 255 - dst.at<uchar>(i, j);
		}
	}
	imshow("非锐化模板", dst1);
	addWeighted(src, 1, dst, 1, 0, dst1);
	addWeighted(src, 1, dst, 4.5, 0, dst);
	imshow("使用非锐掩蔽的结果", dst1);
	imshow("使用高提升滤波的结果", dst);
}


// Sobel算子
void Chapter3::SobelOperator()
{
	// TODO: 在此处添加实现代码.
}


// 锐化滤波器-Sobel算子
void Chapter3::SharpeningFilterSobelOperator(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("原图像", src);

	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	imshow("Sobel_x图像", dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	imshow("Sobel_y原图像", dst1);
	
	addWeighted(dst, 0.5, dst1, 0.5, 0, dst);
	imshow("Sobel_(x+y)原图像", dst);

}


// 混合空间增强
void Chapter3::CombiningSpatialEnhancement(std::string filename)
{
	// TODO: 在此处添加实现代码.
	Mat dst1,dst2,src = imread(filename, 0);
	imshow("全身骨骼扫描图像", src);
	Mat dst(src.size(), CV_16SC1);
	Laplacian(src, dst, CV_16S, 1);
	Mat src1(src.size(), CV_16SC1);
	for (int i = 0; i < src1.rows; i++)
	{
		for (int j = 0; j < src1.cols; j++)
		{
			src1.at<short>(i, j) = (short)src.at<uchar>(i, j);
		}
	}
	addWeighted(src1, 1, dst, -1, 0, dst);
	convertScaleAbs(dst, dst2);
	imshow("拉普拉斯算子滤波后的图像", dst2);
	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	addWeighted(dst, 1, dst1, 1, 0, dst);
	blur(dst, dst, Size(5,5));
	imshow("Sobel图像处理的结果", dst);
	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			dst.at<uchar>(i, j) = (uchar)((float)dst.at<uchar>(i, j)*(float)dst2.at<uchar>(i, j) / 255);
		}
	}

	imshow("Sobel图像处理的结果1", dst);
	addWeighted(src, 1, dst, 1, 0, dst);
	imshow("Sobel图像处理的结果2", dst);
	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			dst.at<uchar>(i, j) = pow(dst.at<uchar>(i, j), 0.5) / pow(255, 0.5) * 255;
		}
	}
	imshow("Sobel图像处理的结果3", dst);
	/*convertScaleAbs(dst, dst);
	imshow("拉普拉斯算子滤波后的图像", dst);

	LaplaceOperator(src, dst1, dst2);
	addWeighted(src, 1, dst, -1, 0, dst);
	imshow("拉普拉斯算子增强后的图像", dst);

	addWeighted(src, 1, dst2, -1, 0, dst2);
	imshow("拉普拉斯算子增强后的图像2", dst2);

	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	addWeighted(dst, 0.5, dst1, 0.5, 0, dst);
	imshow("Sobel图像处理的结果", dst);*/
}
