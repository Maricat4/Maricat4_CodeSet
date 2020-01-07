#pragma once
#include "pch.h"

class Chapter3
{
public:
	Chapter3();
	~Chapter3();

	// ͼ��ĻҶȱ任
	static void GrayTransform(std::string src);
	// �ֶ����Ա任����
	static void SegmentationGrayTrans(std::string src);
	// �Ҷȼ��ֲ�
	static void GrayScaleLayering(std::string filename);
	// ����ƽ��ֲ�
	static void BitPlaneLayering(std::string filename);
	// �жϻҶȼ��ֲ�
	static bool BitLevelJudge(uchar gray, int layer);
	// ֱ��ͼ���⻯
	static void HistogramEqualization(std::string filename);
	// ��ʾͼ���ֱ��ͼ
	static void VisualizationHist(std::string filename);
	// ΪMat���Ҷ�ͼ�������ǵ�ͨ���Ҷ�ͼ�ſ���
	static void VisualizationHistForMat(cv::Mat mat,std::string windowname);
	// ֱ��ͼƥ�䣨ֱ��ͼ�涨����
	static void HistogramMatching(std::string filename1,std::string filename2);
	// �ֲ�ֱ��ͼ����
	static void LocalHistogramEqualization(std::string filename);
	// ʹ��ֱ��ͼͳ�ƾֲ���ǿ
	static void HistogramStatistics(std::string filename);
	// ����Mat�ľ�ֵ�뷽��
	static void CalcMeanAndVariance(cv::Mat A, double& mean, double& Variance);
	// ƽ���˲���
	static void SmoothingFilter(std::string filename,std::string filename1);
	// �Լ���д���˲��������
	static void SmoothingFilterByOwn(cv::Mat A, cv::Mat &dst, cv::Size ksize);
	// ͳ�������˲���-��ֵ�˲�
	static void MedianFilter(std::string filename);
	// ���˲���-������˹����
	static void SharpeningFilterLaplaceOperator(std::string filename);
	// ������˹����
	static void LaplaceOperator(cv::Mat A, cv::Mat &dst, cv::Mat &dst1);
	// �����˲��Լ��������˲�
	static void NonShrpeningAndHighBoost(std::string filename);
	// Sobel����
	static void SobelOperator();
	// ���˲���-Sobel����
	static void SharpeningFilterSobelOperator(std::string filename);
	// ��Ͽռ���ǿ
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


// ͼ��ĻҶȱ任,ͼ��ת�������任��٤��任
void Chapter3::GrayTransform(std::string src)
{
	Mat Src = imread(src);// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src1;
	Mat Src_1(Src.size(), CV_8UC1, Scalar(0));
	Mat Src_2(Src.size(), CV_8UC1, Scalar(0));
	Mat Src_3(Src.size(), CV_8UC1, Scalar(0));
	cvtColor(Src, Src1, CV_BGR2GRAY);
	imshow("ԭʼͼ��", Src);
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
		imshow("��ת���ͼ��", Src_1);
		imshow("�����任���ͼ��", Src_2);
		imshow("٤��任���ͼ��", Src_3);
	}
	else {
		cout << "�ǻҶ�ͼ";
	}
	
	
}


// �ֶ����Ա任����
void Chapter3::SegmentationGrayTrans(std::string src)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat A= imread(src,0);
	Mat Src,Src1;
	if (A.channels() == 3)
		cvtColor(A, Src, CV_BGR2GRAY);
	else Src = A.clone();
	Src1 = Src.clone();
	imshow("ԭʼͼ��",Src);
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
	cout << "��С�Ҷ�ֵ"<< (int)min<<endl;
	cout << "���Ҷ�ֵ"<< (int)max<<endl;
	aver = (uchar)average;
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if(Src.at<uchar>(i, j)>=min && Src.at<uchar>(i, j) <= max)
			//ֵ��ע��ĵط�
			//Src.at<uchar>(i, j) = (((float)255 / (max - min)) * Src.at<uchar>(i, j) + (float)255 * min / (min - max));
			Src.at<uchar>(i, j) = 255 / (max - min) * (Src.at<uchar>(i, j)-min);
			else Src.at<uchar>(i, j) = 0;
			if (Src1.at<uchar>(i, j) >= aver)  Src1.at<uchar>(i, j) = 255;
			else Src1.at<uchar>(i, j) = 0;
		}
	}
	imshow("�Աȶ�������ͼ��",Src);
	imshow("��ֵ������ͼ��", Src1);
}


// �Ҷȼ��ֲ�
void Chapter3::GrayScaleLayering(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src = imread(filename, 0);
	Mat Src1 = Src.clone();
	imshow("ԭͼ��",Src);
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
	imshow("��һͼ��", Src);
	imshow("����ͼ��", Src1);
}


// ����ƽ��ֲ�
void Chapter3::BitPlaneLayering(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src = imread(filename, 0);
	imshow("ԭͼ��", Src);
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
			//���ñ���ƽ���ؽ�ͼ��
			a.at<uchar>(i, j) = Src0[6].at<uchar>(i, j)/255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
			b.at<uchar>(i, j) = Src0[5].at<uchar>(i, j) / 255 * 32 + Src0[6].at<uchar>(i, j) / 255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
			c.at<uchar>(i, j) = Src0[4].at<uchar>(i, j) / 255 * 16 + Src0[5].at<uchar>(i, j) / 255 * 32 + Src0[6].at<uchar>(i, j) / 255 * 64 + Src0[7].at<uchar>(i, j) / 255 * 128;
		}
	}
	//threshold(Src, Src8, 127, 255, CV_THRESH_BINARY);
	imshow("��1����ƽ��", Src0[0]);
	imshow("��2����ƽ��", Src0[1]);
	imshow("��3����ƽ��", Src0[2]);
	imshow("��4����ƽ��", Src0[3]);
	imshow("��5����ƽ��", Src0[4]);
	imshow("��6����ƽ��", Src0[5]);
	imshow("��7����ƽ��", Src0[6]);
	imshow("��8����ƽ��", Src0[7]);
	imshow("ʹ�ñ���ƽ��7,8�ؽ�", a);
	imshow("ʹ�ñ���ƽ��6,7,8�ؽ�", b);
	imshow("ʹ�ñ���ƽ��5,6,7,8�ؽ�", c);
}


// �жϻҶȼ��ֲ�
bool Chapter3::BitLevelJudge(uchar gray,int layer)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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


// ֱ��ͼ���⻯
void Chapter3::HistogramEqualization(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	//ԭͼ��
	Mat Src = imread(filename, 0);
	imshow("ԭͼ��", Src);
	VisualizationHistForMat(Src,"ԭͼֱ��ͼ");
	//ӳ�������ػҶ�ֵ
	float s;
	//���Ҷ�ֵ
	int L = 256;
	//�Ҷȼ�ͳ��
	Mat hist;
	//ӳ�亯��
	int T[256];
	//����ͳ��
	float sum = 0;
	int MN = Src.size().area();
	//����ԭͼ�����ص�Ƶ��
	//�Ҷȷ�Χ
	float range[] = { 0,256 };
	const float *histRanges = { range };
	calcHist(&Src, 1, 0, Mat(), hist, 1, &L, &histRanges, true, false);
	//����ӳ�亯��
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
	imshow("������ͼ��", Src);
	VisualizationHistForMat(Src,"������ֱ��ͼ");
	
	equalizeHist(Src1, Src1);
	imshow("OpenCV_API������ͼ��", Src1);
	VisualizationHistForMat(Src1, "OpenCV_API������ֱ��ͼ");
}


// ��ʾͼ���ֱ��ͼ
void Chapter3::VisualizationHist(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	//Դͼ��
	Mat Src = imread(filename, 0);
	//�Ҷ�
	imshow("ԭʼͼ��", Src);
	//��ϡ��
	Mat hist;

	int histSize = 256;
	//�Ҷȷ�Χ
	float range[] = { 0,256 };
	const float *histRanges = { range };
	//ͼ��ߣ����Լ�С���εĿ��
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = 2;
	//ֱ��ͼ�Ҷ�ͼ ����
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	//����ԭͼ�����ص�Ƶ��
	calcHist(&Src, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);
	Rect a;
	float height = 0;
	//��ֱ��ͼ����
	for (int i = 0; i < histSize; i++)
	{
		height = 10*hist_h * (hist.at<float>(i) / Src.size().area());
		a = Rect(Point(bin_w*i,400 -height) ,Size(bin_w-1, height));
		rectangle(histImage, a, Scalar(255, 255, 255));
	}
	imshow("ֱ��ͼ", histImage);
}



// ΪMat���Ҷ�ͼ�������ǵ�ͨ���Ҷ�ͼ�ſ���
void Chapter3::VisualizationHistForMat(Mat mat,string windowname="NULL")
{
	// TODO: �ڴ˴����ʵ�ִ���.
	//Դͼ��
	Mat Src = mat;
	//��ʾԭͼ
	//imshow("ԭʼͼ��", Src);
	//��ϡ��
	Mat hist;

	int histSize = 256;
	//�Ҷȷ�Χ
	float range[] = { 0,256 };
	const float *histRanges = { range };
	//ͼ��ߣ����Լ�С���εĿ��
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = 2;
	//ֱ��ͼ�Ҷ�ͼ ����
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	//����ԭͼ�����ص�Ƶ��
	calcHist(&Src, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);
	Rect a;
	float height = 0;
	//��ֱ��ͼ����
	for (int i = 0; i < histSize; i++)
	{
		height = 10 * hist_h * (hist.at<float>(i) / Src.size().area());
		a = Rect(Point(bin_w*i, 400 - height), Size(bin_w - 1, height));
		rectangle(histImage, a, Scalar(255, 255, 255));
	}
	if(windowname!="NULL")
	imshow(windowname, histImage);
}


// ֱ��ͼƥ�䣨ֱ��ͼ�涨����
void Chapter3::HistogramMatching(std::string filename1, ::string filename2)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src = imread(filename1, 0);
	Mat Target = imread(filename2, 0);
	imshow("ԭͼ��", Src);
	imshow("��Ҫƥ���ֱ��ͼͼ��", Target);
	VisualizationHistForMat(Src, "ԭͼ���ֱ��ͼ");
	VisualizationHistForMat(Target, "��Ҫƥ���ֱ��ͼͼ��ֱ��ͼ");

	//��һ�� ֱ��ͼ���⻯
	equalizeHist(Src, Src);
	Mat hist;
	//�Ҷȷ�Χ
	float range[] = { 0,256 };
	const float *histRanges = { range };
	int histSize = 256;
	
	//Mat hist;
	calcHist(&Target, 1, 0, Mat(), hist, 1, &histSize, &histRanges, true, false);

	int sum = 0;
	float z;
	int MN = Target.size().area();
	int G[256];
	//����ӳ�亯��
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
	imshow("ƥ����ͼ��", Src);
	VisualizationHistForMat(Src, "ƥ���ͼ���ֱ��ͼ");
}


// �ֲ�ֱ��ͼ����
void Chapter3::LocalHistogramEqualization(string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src = imread(filename, 0);
	Mat Src_hist(Src.size(),Src.type());
	imshow( "ԭͼ��", Src);
	VisualizationHistForMat(Src,"ԭͼ��ĻҶ�ͼ");
	equalizeHist(Src, Src_hist);
	imshow("ֱ��ͼ���⻯ͼ��", Src_hist);
	VisualizationHistForMat(Src_hist, "ֱ��ͼ���⻯ͼ��ĻҶ�ͼ");
	
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
	imshow("�ֲ�ֱ��ͼ���⻯ͼ��", Src);
	VisualizationHistForMat(Src, "�ֲ�ֱ��ͼ���⻯ͼ��ĻҶ�ͼ");

}


// ʹ��ֱ��ͼͳ�ƾֲ���ǿ
void Chapter3::HistogramStatistics(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat Src = imread(filename, 0);
	Mat Src_hist;
	imshow("ԭͼ��", Src);
	VisualizationHistForMat(Src, "ԭͼ��ֱ��ͼ");
	equalizeHist(Src, Src_hist);
	imshow("ȫ��ֱ��ͼ����", Src_hist);
	VisualizationHistForMat(Src_hist, "ȫ��ֱ��ͼ����ֱ��ͼ");
	//ȫ��ƽ���Ҷ�ֵ�Լ�ȫ�ֻҶȷ���
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
	//��������
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
			//��������ľ�ֵ�뷽��
			CalcMeanAndVariance(temp, mean, Variance);
			if (mean <= (k0 * m) && Variance >= (k1 * s2) && Variance <= (k2 * s2)) {
				Src1.at<uchar>(i, j) = E * Src.at<uchar>(i, j);
			}
			
		}
		
	}
	imshow("ֱ��ͼͳ����ǿ", Src1);
	VisualizationHistForMat(Src1,"ֱ��ͼͳ����ǿֱ��ͼ");
}


// ����Mat�ľ�ֵ�뷽��
void Chapter3::CalcMeanAndVariance(cv::Mat A, double& mean, double& Variance)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
	//cout <<"��ֵ��" <<mean<<endl;
	
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
	//cout << "���" << Variance << endl;
	
}


// ƽ���˲���
void Chapter3::SmoothingFilter(std::string filename,std::string filename1)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat src = imread(filename, 0);
	Mat src1 = imread(filename1, 0);
	imshow("ԭͼ��",src);
	Mat dst;
	boxFilter(src, dst,src.depth(),Size(3,3));
	imshow("3x3���ξ�ֵ�˲�ԭͼ��", dst);
	boxFilter(src, dst, src.depth(), Size(5, 5));
	imshow("5x5���ξ�ֵ�˲�ԭͼ��", dst);
	/*boxFilter(src, dst, src.depth(), Size(9, 9));
	imshow("9x9���ξ�ֵ�˲�ԭͼ��", dst);
	boxFilter(src, dst, src.depth(), Size(15, 15));
	imshow("15x15���ξ�ֵ�˲�ԭͼ��", dst);
	boxFilter(src, dst, src.depth(), Size(35, 35));
	imshow("35x35���ξ�ֵ�˲�ԭͼ��", dst);*/

	/*SmoothingFilterByOwn(src, dst, Size(3, 3));
	imshow("3x3���ξ�ֵ�˲�ͼ��", dst);
	SmoothingFilterByOwn(src, dst, Size(5, 5));
	imshow("5x5���ξ�ֵ�˲�ͼ��", dst);
	SmoothingFilterByOwn(src, dst, Size(9, 9));
	imshow("9x9���ξ�ֵ�˲�ԭͼ��", dst);
	SmoothingFilterByOwn(src, dst, Size(15, 15));
	imshow("15x15���ξ�ֵ�˲�ԭͼ��", dst);
	SmoothingFilterByOwn(src, dst, Size(35, 35));
	imshow("35x35���ξ�ֵ�˲�ԭͼ��", dst);*/
	imshow("������Զ��ͼ��", src1);
	boxFilter(src1, dst, src.depth(), Size(15, 15));
	imshow("������Զ��15x15���ξ�ֵ�˲���ͼ��", dst);
	threshold(dst, dst, 70, 255, CV_THRESH_BINARY);
	imshow("��ֵ����ͼ��", dst);
}




// �Լ���д�ľ�ֵ�˲��������
// ��Ϊȫ1����
void Chapter3::SmoothingFilterByOwn(cv::Mat A, cv::Mat &dst, cv::Size ksize = Size(3, 3))
{
	// TODO: �ڴ˴����ʵ�ִ���.
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


// ͳ�������˲���-��ֵ�˲�-��Сֵ�˲�-���ֵ�˲�
void Chapter3::MedianFilter(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat dst,src = imread(filename, 0);
	imshow("ԭͼ��", src);
	blur(src, dst, Size(3, 3));
	imshow("��ֵ�˲�ͼ��", dst);
	medianBlur(src, dst, 3);
	imshow("��ָ�˲�ͼ��", dst);
}


// ���˲���-������˹����
void Chapter3::SharpeningFilterLaplaceOperator(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("ԭͼ��", src);
	Laplacian(src, dst, CV_16SC1,1,1,0,4);
	Mat src1(src.size(), CV_16SC1);
	for (int i = 0; i < src1.rows; i++)
	{
		for (int j = 0; j < src1.cols; j++)
		{
			src1.at<short>(i, j) = (short)src.at<uchar>(i, j);
		}
	}
	
	//imshow("������˹�����˲����ͼ��1", dst);
	Mat dst2 = dst.clone();
	addWeighted(src1, 1, dst, 1, 0, dst);
	convertScaleAbs(dst, dst);
	imshow("������˹�����˲���Ļ��ͼ��00", dst);
	addWeighted(src1, 1, dst2, -1, 0, dst);
	convertScaleAbs(dst, dst);
	imshow("������˹�����˲���Ļ��ͼ��01", dst);
	LaplaceOperator(src, dst, dst1);
	//imshow("������˹�����˲���ͼ��", dst);
	//imshow("������˹����(�ӶԽ��߷���)�˲���ͼ��", dst1);

	dst2 = dst.clone();
	//cout << dst2;
	addWeighted(src, 1, dst,  1, 0, dst);
	imshow("������˹�����˲���Ļ��ͼ��", dst);
	addWeighted(src, 1, dst2, -1, 0, dst);
	imshow("������˹�����˲���Ļ��ͼ��1", dst);
	dst2 = dst1.clone();
	addWeighted(src, 1, dst1, -1, 0, dst1);
	imshow("������˹����(�ӶԽ��߷���)�˲���Ļ��ͼ��", dst1);
	addWeighted(src, 1, dst2, 1, 0, dst1);
	imshow("������˹����(�ӶԽ��߷���)�˲���Ļ��ͼ��1", dst1);
}


// ������˹����
void Chapter3::LaplaceOperator(cv::Mat A,cv::Mat &dst, cv::Mat &dst1)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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

			//�궨���ͼ��
			temp_ = (float)(temp1.at<short>(i, j) - min1) / (max1 - min1) * 255;
			temp3.at<uchar>(i, j) = temp_;
		}
	}
	imshow("����1�궨ͼ��", temp2);
	imshow("����2�궨ͼ��", temp3);

}


// �����˲��Լ��������˲�
void Chapter3::NonShrpeningAndHighBoost(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("ԭͼ��", src);
	GaussianBlur(src, dst, Size(5,5), 3);
	imshow("ʹ�ø�˹�˲���ģ���Ľ��",dst);
	addWeighted(src, 1, dst, -1, 0, dst);
	dst1 = dst.clone();
	for (int i = 0; i < dst.size().height; i++)
	{
		for (int j = 0; j < dst.size().width; j++)
		{
			dst1.at<uchar>(i, j) = 255 - dst.at<uchar>(i, j);
		}
	}
	imshow("����ģ��", dst1);
	addWeighted(src, 1, dst, 1, 0, dst1);
	addWeighted(src, 1, dst, 4.5, 0, dst);
	imshow("ʹ�÷����ڱεĽ��", dst1);
	imshow("ʹ�ø������˲��Ľ��", dst);
}


// Sobel����
void Chapter3::SobelOperator()
{
	// TODO: �ڴ˴����ʵ�ִ���.
}


// ���˲���-Sobel����
void Chapter3::SharpeningFilterSobelOperator(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat dst,dst1,src = imread(filename, 0);
	imshow("ԭͼ��", src);

	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	imshow("Sobel_xͼ��", dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	imshow("Sobel_yԭͼ��", dst1);
	
	addWeighted(dst, 0.5, dst1, 0.5, 0, dst);
	imshow("Sobel_(x+y)ԭͼ��", dst);

}


// ��Ͽռ���ǿ
void Chapter3::CombiningSpatialEnhancement(std::string filename)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Mat dst1,dst2,src = imread(filename, 0);
	imshow("ȫ�����ɨ��ͼ��", src);
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
	imshow("������˹�����˲����ͼ��", dst2);
	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	addWeighted(dst, 1, dst1, 1, 0, dst);
	blur(dst, dst, Size(5,5));
	imshow("Sobelͼ����Ľ��", dst);
	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			dst.at<uchar>(i, j) = (uchar)((float)dst.at<uchar>(i, j)*(float)dst2.at<uchar>(i, j) / 255);
		}
	}

	imshow("Sobelͼ����Ľ��1", dst);
	addWeighted(src, 1, dst, 1, 0, dst);
	imshow("Sobelͼ����Ľ��2", dst);
	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			dst.at<uchar>(i, j) = pow(dst.at<uchar>(i, j), 0.5) / pow(255, 0.5) * 255;
		}
	}
	imshow("Sobelͼ����Ľ��3", dst);
	/*convertScaleAbs(dst, dst);
	imshow("������˹�����˲����ͼ��", dst);

	LaplaceOperator(src, dst1, dst2);
	addWeighted(src, 1, dst, -1, 0, dst);
	imshow("������˹������ǿ���ͼ��", dst);

	addWeighted(src, 1, dst2, -1, 0, dst2);
	imshow("������˹������ǿ���ͼ��2", dst2);

	Sobel(src, dst, CV_16S, 1, 0);
	convertScaleAbs(dst, dst);
	Sobel(src, dst1, CV_16S, 0, 1);
	convertScaleAbs(dst1, dst1);
	addWeighted(dst, 0.5, dst1, 0.5, 0, dst);
	imshow("Sobelͼ����Ľ��", dst);*/
}
