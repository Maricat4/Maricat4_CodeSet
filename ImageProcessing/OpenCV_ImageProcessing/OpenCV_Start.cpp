// OpenCV_Start.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Chapter1_Basic.h"
#include "pch.h"

void FormalParameter(int a, int &b, int *c) {
	cout <<"值传递变量："<< a << endl;
	cout << "值传递地址：" << &a << endl;
	cout << "引用传递变量："<< b <<endl;
	cout << "引用传递地址："<< &b <<endl;
	cout << "指针传递变量："<< c << endl;
	cout << "指针传递地址："<< &c << endl;

}

int main()
{ 
	cout<<"chcp"<<GetConsoleOutputCP()<<endl;
	cout<<"嬲"<<endl;
	SetConsoleOutputCP(65001);
	cout<<"chcp"<<GetConsoleOutputCP()<<endl;
	cout<<"嬲"<<endl;
	
	try
	{
			//测试函数
		// string s = "E:\\MasterCode\\OpenCV\\lena.tif";
		// cout<<s<<endl;
		// int a = 8,&b=a,*c = &a;
		// Mat src = imread(s);
		//FormalParameter(a,b,c);
		//Chapter1_Basic::Voronoi(s);
		//Chapter1_Basic::ResizeImg("pic//girl.tiff",4,4);
		//Chapter1_Basic::ResizeJ(s);
		
		//Chapter3 a;
		Chapter3::GrayTransform("E:\\MasterCode\\OpenCV\\lena.tif");
		//Chapter3::SegmentationGrayTrans("pic//Fig0310.tif");
		//Chapter3::GrayScaleLayering("pic//Fig0312.tif");
		//a.BitPlaneLayering(s);
		//Chapter3::VisualizationHist("pic//Fig0320_3.tif");
		//Chapter3::HistogramEqualization("pic//Fig0320_4.tif");
		//Chapter3::HistogramMatching("pic//Fig0320_4.tif", "pic//Fig0320_2.tif");
		//Chapter3::LocalHistogramEqualization("pic//CH03//Fig0326.tif");
		//Chapter3::HistogramStatistics("pic//CH03//Fig0327.tif");
		//Chapter3::SmoothingFilter("pic//CH03//Fig0333.tif","pic//CH03//Fig0334.tif");
		//Chapter3::MedianFilter("pic//CH03//Fig0335.tif");
		//Chapter3::SharpeningFilterLaplaceOperator("pic//CH03//Fig0338.tif");
		//Chapter3::NonShrpeningAndHighBoost("pic//CH03//Fig0340.tif");
		//Chapter3::SharpeningFilterSobelOperator("pic//CH03//Fig0342.tif");
		//Chapter3::CombiningSpatialEnhancement("pic//CH03//Fig0343.tif");

		//Chapter9::Eroding("pic//CH09//Fig0905(a)(wirebond-mask).tif");  
		//Chapter9::CV_Dilating("pic//CH09//Fig0907(a)(text_gaps_1_and_2_pixels).tif");  
		//Chapter9::Dilating("pic//CH09//Fig0907(a)(text_gaps_1_and_2_pixels).tif");  
		//Chapter9::CV_Eroding("pic//CH09//Fig0905(a)(wirebond-mask).tif");  
		//Chapter9::CV_Duality("pic//CH09//Fig0905(a)(wirebond-mask).tif");  
		//Chapter9::CV_OPEN_CLOSE("pic//CH09//Fig0911(a)(noisy_fingerprint).tif");
		//Chapter9::CV_HMT_TRANSFORM("pic//CH09//FigP0918(left).tif");
		//Chapter9::CV_BoundaryExtraction("pic//CH09//Fig0914(a)(licoln from penny).tif");
		//Chapter9::CV_HoleFilling("pic//CH09//Fig0916(a)(region-filling-reflections).tif");
		//Chapter9::CV_ExtractionOFConnectedComponents("pic//CH09//Fig0918(a)(Chickenfilet with bones).tif");
		//Chapter9::CV0_ErodingANDDilating("pic//CH09//FigP0905(U).tif");
		//Chapter9::CV_Convex("pic//CH09//test.png");
		//Chapter9::CV0_ErodingANDDilating2();
		//cout<<CV_VERSION<<endl;

		{
			cout<<"stupid"<<endl;
		}


		// try
		// {
		// 	Chapter9::Dilating("pic//CH09//Fig0907(a)(text_gaps_1_and_2_pixels).tif");  
		// }
		// catch(const cv::Exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// 	system("pause"); 
		// }


		


		// string s = "pic//CH04//pic3.jpg";
		// cout<<s<<endl;
		// Mat src = imread(s,0);
		//cout<<src.size()<<endl;
		// try
		// {
			
		// try
		// {
		// 	Chapter4::HoughW(src);
		// }
		// catch(const cv::Exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// }
			
		
		// }
		// catch(exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// }
		
		
		/*Mat la1, la2;
		la1 = (Mat_<short int>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
		la2 = (Mat_<short int>(3, 3) << 1, 1, 1, 1, -4, 1, 1, 1, 1);
		cout << la1.at<short>(1, 1);*/
		//int ans = 10;
		//FormalParameter(ans, ans, &ans);
	}
	catch(const cv::Exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	waitKey(0);
	system("pause");
    //cout << "Hello World!\n"; 
	return 0;
}