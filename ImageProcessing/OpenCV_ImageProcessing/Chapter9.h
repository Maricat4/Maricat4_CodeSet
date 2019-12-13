#pragma once
#include "pch.h"
class Chapter9
{
public:
    //膨胀
    static void Dilating(const string &);
    //腐蚀
    static void Eroding(const string &);
    //OpenCV——腐蚀
    static void CV_Eroding(const string &);
    //腐蚀与膨胀 当结构元素不再是1，为0时,使用图片
    static void CV0_ErodingANDDilating(const string  &);
    //腐蚀与膨胀 当结构元素不再是1，为0时,使用矩阵
    static void CV0_ErodingANDDilating2();
    //OpenCV——膨胀
    static void CV_Dilating(const string &);

    //对偶性
    static void CV_Duality(const string &);

    //开操作,闭操作
    static void CV_OPEN_CLOSE(const string &);

    //击中击不中变换-HMT transform
    static void CV_HMT_TRANSFORM(const string &);

    //边界提取
    static void CV_BoundaryExtraction(const string &);
    //孔洞填充
    static void CV_HoleFilling(const string  &);
    //连通分量的提取
    static void CV_ExtractionOFConnectedComponents(const string &);
    //凸包
    static void CV_Convex(const string &);
};

void Chapter9::Dilating(const string &a){
    Mat _m1 = imread(a,0);
    Mat m1 = Mat::ones(Size(11,11),CV_8UC1), m2 = Mat::ones(Size(15,15),CV_8UC1),m3 = Mat::ones(Size(45,45),CV_8UC1);
    Mat _m3 = Mat::zeros(_m1.size(),_m1.type());
    Mat _m2 = _m1.clone();
    int sumtemp = 0,N = 0;
    Mat m0 = (Mat_<uchar>(3,3)<<0,1,0,1,1,1,0,1,0);
    //cout<<m0<<endl;
    //Chapter3::VisualizationHistForMat(_m1,"_m1");
   // cout<<_m1<<endl;
    for (size_t i = 1; i < _m1.rows-1; i++)
    {
        for (size_t j = 1; j < _m1.cols-1; j++)
        {
            //3x3结构元素膨胀
            sumtemp = 0;
            N = 3;
            if(_m1.at<uchar>(i,j)==255){

                for (size_t x = 0; x < N; x++)
                {
                    for (size_t y = 0; y < N; y++)
                    {
                        sumtemp+= m0.at<uchar>(x,y)*m1.at<uchar>(i-1+x,j-1+y);
                        //_m2.at<uchar>(i+x-1,j+y-1) = (255*m0.at<uchar>(x,y) > _m1.at<uchar>(i+x-1,j+y-1)) ? 255*m0.at<uchar>(x,y) : _m1.at<uchar>(i+x-1,j+y-1);
                        //if(255*mo.at<uchar>(x,y) > _m1.at<uchar>)
                        if(_m3.at<uchar>(i+x-1,j+y-1)!=255)
                            _m3.at<uchar>(i+x-1,j+y-1) = 255*m0.at<uchar>(x,y) > _m1.at<uchar>(i+x-1,j+y-1) ? 255 : _m1.at<uchar>(i+x-1,j+y-1);
                        
                        // if(m0.at<uchar>(x,y)==1)
                        //     _m3.at<uchar>(i+x-1,j+y-1) = 255;
                         if(m0.at<uchar>(x,y)==1 &&_m3.at<uchar>(i+x-1,j+y-1) != 255)
                            cout<<1<<",i="<<i+x-1<<",j="<<j+y-1<<endl;
                        // if(_m1.at<uchar>(i-1+x,j-1+y)==0&&m0.at<uchar>(x,y)==1){
                        //     _m1.at<uchar>(i-1+x,j-1+y)==255;
                        // }
                    }
                    
                }
                if(sumtemp<255*5){
                    for (size_t x = 0; x < N; x++)
                    {
                        for (size_t y = 0; y < N; y++)
                        {
                            if(_m1.at<uchar>(i-1+x,j-1+y)==0 && m0.at<uchar>(x,y)==1){
                                _m2.at<uchar>(i-1+x,j-1+y)=255;
                            }
                        }
                        
                    }
                    
                }
            }
            //cout<<sumtemp<<endl;
            //throw Exception();
            // if(sumtemp > 0){
            //     for (size_t x = 0; x < N; x++)
            //     {
            //         for (size_t y = 0; y < N; y++)
            //         {
                        
            //              _m2.at<uchar>(i+x-1,j+y) = 255*m0.at<uchar>(x,y) > _m1.at<uchar>(i+x-1,j+y-1) ? 255*m0.at<uchar>(x,y) : _m1.at<uchar>(i+x-1,j+y-1);
            //         }
                    
            //     }
                
            // }
        }
        
    }
    imshow("3x3",_m3);
    imshow("3x32",_m2);
    imshow("_m3 - _m2",_m2 - _m3);
    imshow("_m3 - _m1",_m2 - _m1);
}
void Chapter9::Eroding(const string &a){
    Mat _m1 = imread(a,0);
    imshow("源图像",_m1);
    //threshold(_m1,_m1,128,255,CV_THRESH_BINARY);
    //imshow("二值化图像",_m1);
    Mat m1 = Mat::ones(Size(11,11),CV_8UC1), m2 = Mat::ones(Size(15,15),CV_8UC1),m3 = Mat::ones(Size(45,45),CV_8UC1);
    Mat _m2 = Mat::zeros(_m1.size(),_m1.type()),_m3= Mat::zeros(_m1.size(),_m1.type()),_m4 = Mat::zeros(_m1.size(),_m1.type());
    int sumtemp = 0,N = 0;
    for (size_t i = 0; i < _m1.rows; i++)
    {
        for (size_t j = 0; j < _m1.cols; j++)
        {
            //11x11结构元素腐蚀
            sumtemp = 0;
            N = 11;
            for (size_t x = 0; x < N; x++)
            {
                for (size_t y = 0; y < N; y++)
                {
                    if(i+x<_m1.rows&&j+y<_m1.cols)
                        sumtemp += m1.at<uchar>(x,y)*_m1.at<uchar>(i+x,j+y);
                }
                
            }
            //cout<<sumtemp<<endl;
            //throw Exception();
            if(sumtemp == N*N*255){
                _m2.at<uchar>(i,j) = _m1.at<uchar>(i,j);
            }else
            {
                _m2.at<uchar>(i,j) = 0;
            }
            
            //15x15结构元素腐蚀
            sumtemp = 0;
            N = 15;
            for (size_t x = 0; x < N; x++)
            {
                for (size_t y = 0; y < N; y++)
                {
                    if(i+x<_m1.rows&&j+y<_m1.cols)
                    sumtemp += m2.at<uchar>(x,y)*_m1.at<uchar>(i+x,j+y);
                    
                }
                
            }
            if(sumtemp == N*N*255){
                _m3.at<uchar>(i,j) = _m1.at<uchar>(i,j);
            }else
            {
                _m3.at<uchar>(i,j) = 0;
            }
            //45x45结构元素腐蚀
            sumtemp = 0;
            N = 45;
            for (size_t x = 0; x < N; x++)
            {
                for (size_t y = 0; y < N; y++)
                {
                    if(i+x<_m1.rows&&j+y<_m1.cols)
                    sumtemp += m3.at<uchar>(x,y)*_m1.at<uchar>(i+x,j+y);
                    
                }
                
            }
            if(sumtemp == N*N*255){
                _m4.at<uchar>(i,j) = _m1.at<uchar>(i,j);
            }else
            {
                _m4.at<uchar>(i,j) = 0;
            }
        }
        
    }
    //imshow("原图",_m1);
    imshow("11x11",_m2);
    imshow("15x15",_m3);
    imshow("45x45",_m4);
}

void Chapter9::CV_Dilating(const string &a){
    Mat _m1 = imread(a,0);
    Mat _m2,_m3;
   // Mat element = getStructuringElement()
    imshow("原图像",_m1);
    dilate(_m1,_m2,getStructuringElement(MORPH_CROSS,Size(3,3)));
    imshow("膨胀后CROSS",_m2);
    dilate(_m1,_m3,getStructuringElement(MORPH_RECT,Size(3,3)));
    imshow("膨胀后RECT",_m3);
    //dilate()
}

void Chapter9::CV_Eroding(const string &a){
    Mat _m1 = imread(a,0);
    imshow("原图",_m1);
    Mat _m2,_m3,_m4;
    erode(_m1,_m2,getStructuringElement(MORPH_RECT,Size(11,11)));
    erode(_m1,_m3,getStructuringElement(MORPH_RECT,Size(15,15)));
    erode(_m1,_m4,getStructuringElement(MORPH_RECT,Size(45,45)));
    imshow("11x11腐蚀后",_m2);
    imshow("15x15腐蚀后",_m3);
    imshow("45x45腐蚀后",_m4);
}

void Chapter9::CV_Duality(const string &a){
    Mat _m1 = imread(a,0);
    imshow("原图",_m1);
    Mat _m2,_m3,_m4;
    
    Mat _strl = getStructuringElement(MORPH_RECT,Size(11,11));
    Mat _m0 = Mat::ones(_m1.size(),_m1.type())*255;
    _m4 = _m0 - _m1;

    imshow("_m0",_m4);

    erode(_m1,_m2,_strl);
    dilate(_m4,_m3,_strl);

    imshow("腐蚀原图",_m2);
    imshow("膨胀补集",_m0 - _m3);

}

void Chapter9::CV_OPEN_CLOSE(const string &a){
    Mat _m1 = imread(a,0);
    imshow("原图",_m1);
    Mat _m2,_m3,_m4;
    //开操作
    Mat m0 = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(_m1,_m2,m0);
    dilate(_m2,_m2,m0);
    imshow("开操作",_m2);

    dilate(_m2,_m2,m0);
    erode(_m2,_m2,m0);
    imshow("开操作后闭操作",_m2);
    //imshow("开操作与原图作差",_m1 - _m2);


}

void Chapter9::CV_HMT_TRANSFORM(const string &str){
    Mat _m1 = imread(str,0);
    imshow("原图",_m1);
    
    Mat b1 = (Mat_<uchar>(3,3)<<0,0,0,0,1,1,0,1,1);
    Mat b2 = (Mat_<uchar>(3,3)<<1,1,1,1,1,0,1,0,0);

    Mat_<uchar> b3(5,5);
    b3<<1,1,1,1,1,1,1,1,1,1;
    Mat b4(Size(3,3),CV_8UC1);
    cout<<b3<<endl;
    Mat _m2,_m3 =  Mat_<uchar>(_m1.size(),255) - _m1;
    imshow("_m3_0",_m3);
    erode(_m1,_m2,b1);
    _m2/=255;
    erode(_m3,_m3,b2);
    imshow("_m30",_m3);
    _m3/=255;
    _m3 = ((_m2+_m3)-(_m2+_m3)/(_m2+_m3))*255;
    imshow("_m3",_m3);
    

    morphologyEx(_m1,_m2,MORPH_HITMISS,b1);
    imshow("_m200",_m2);
}

void Chapter9::CV_BoundaryExtraction(const string &str){
    Mat _m1 = imread(str,0);
    Mat strl = getStructuringElement(MORPH_RECT,Size(15,15));
    Mat _m2,_m3;
    imshow("原图",_m1);
    erode(_m1,_m2,strl);
    imshow("erode _m1 by using RectEle",_m2);
    imshow("diference _m1 and _m2",_m1 - _m2);

}

void Chapter9::CV_HoleFilling(const string &str){
    Mat _m1 = imread(str,0);
    Mat _m2 = _m1.clone();
    floodFill(_m2,Point(0,0),Scalar(255));
    imshow("原图",_m1);
    imshow("floodfill_m1",_m2);
    //Mat _m3 = Mat_<uchar>(_m1.size(),255);
    //Mat _m4 = _m3 - _m1;
    //_m4 = _m3 - _m3 - _m2;
    // imshow("_m4",_m4);
    // imshow("_m3",_m3);
    for (size_t i = 0; i < _m1.rows; i++)
    {
        for (size_t j = 0; j < _m1.cols; j++)
        {
            if(_m2.at<uchar>(i,j)==0&&_m1.at<uchar>(i,j)==0){
                _m1.at<uchar>(i,j) = 255;
            }
        }
        
    }
    imshow("holeFilling",_m1);
    
}
int LabelConnectedComponent(const cv::Mat &src, cv::Mat &dst, bool iseight = true)
{
    Mat structelement;
    if(iseight)
        structelement = getStructuringElement(MORPH_RECT, Size(3, 3));
    else
         structelement = getStructuringElement(MORPH_CROSS, Size(3, 3));

    dst = Mat::ones(src.size(), src.type());
    Mat tmp = Mat::ones(src.size(), src.type()); // save last reuslt image
    Mat img = Mat::ones(src.size(), src.type()); //image B
    int labelnum = 0; //label of connected component

    Mat backupsrc;
    src.copyTo(backupsrc);
    for(int i = 0; i < backupsrc.rows; i++)
    {
        for(int j = 0; j < backupsrc.cols; j++)
        {
            if(backupsrc.at<uchar>(i, j) == 255)
            {
                Mat img = Mat::ones(src.size(), src.type());
                img.at<uchar>(i, j) = 255;
                img.copyTo(tmp);  //Temporary save
                labelnum++;

                while(true)  // until not change
                {
                    cv::dilate(img, img, structelement);
                    bitwise_and(img, src, img);
                    //if img do not change, this connected component is finished
                    if (cv::countNonZero(img - tmp) == 0)
                        break;
                    img.copyTo(tmp);
                }


                //label the connected component
                for(int r = 0; r < img.rows; r++)
                {
                    for(int c = 0; c < img.cols; c++)
                    {
                        if(img.at<uchar>(r, c) == 255)
                        {
                            backupsrc.at<uchar>(r, c) = 0;
                            dst.at<uchar>(r, c) = 255-labelnum*10;
                        }
                    }
                }
            }
        }
    }
    imshow("backupsrc",backupsrc);
    return labelnum;
}
void Chapter9::CV_ExtractionOFConnectedComponents(const string &str){
    Mat _m1 = imread(str,0);
    Mat _m2,_m3;
    imshow("原图像",_m1);
    adaptiveThreshold(_m1,_m2,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,0);
    imshow("自适应阈值分割",_m2);
    _m3 = imread("pic\\CH09\\bw_bacteria.bmp",0);
    imshow("细菌图",_m3);
    cout<<LabelConnectedComponent(_m3,_m2);
    imshow("提取后",_m2);

}

void Chapter9::CV_Convex(const string & str){
    Mat _m1 = imread(str,0);
    Mat b1 = (Mat_<uchar>(3,3)<<1,0,0,1,0,0,1,0,0),
        b2 = (Mat_<uchar>(3,3)<<1,1,1,0,0,0,0,0,0),
        b3 = (Mat_<uchar>(3,3)<<0,0,1,0,0,1,0,0,1), 
        b4 = (Mat_<uchar>(3,3)<<0,0,0,0,0,0,1,1,1); 
    imshow("origin",_m1);
    vector<Mat> B = {b1,b2,b3,b4};
    
    Mat b0 = Mat::ones(Size2i(3,3),CV_8UC1);
    Mat temp,dst,dst2,dst3 = _m1.clone();
    Mat TEMP = Mat_<uchar>(_m1.size(),255);
//    temp = _m1.clone();
//     erode(temp,dst,B[0]);
//     erode(TEMP - temp,dst2,b0 - B[0]);
//     bitwise_and(dst,dst2,dst);
//     imshow("temp",dst);
//     bitwise_or(_m1,dst,dst);
//     imshow("temp image",dst);
//     imshow("temp image1",dst - _m1); 
    vector<Mat> temp2;
    for (size_t i = 0; i < 4; i++)
    {
        temp = _m1.clone();
        while (true)
        {
            erode(temp,dst,B[i]);
            erode(TEMP - temp,dst2,b0 - B[i]);
            bitwise_and(dst,dst2,dst);
            if(countNonZero(dst)==0)
                //imshow("temp_",temp);
                break;
            bitwise_or(temp,dst,temp);
        }
        bitwise_or(temp,dst3,dst3);
        temp2.push_back(temp.clone());
    }
    // imshow("temp1",temp2[0]);
    // imshow("temp1_",temp2[1] - _m1);
    // imshow("temp2",temp2[1]);
    // imshow("temp2_",temp2[1] - _m1);
    // imshow("temp3",temp2[2]);
    // imshow("temp3_",temp2[2] - _m1);
    // imshow("temp4",temp2[3]);
    // imshow("temp4_",temp2[3] - _m1);
    imshow("last image",dst3);
    //imshow("last image1",dst3 - _m1);
    
    
}

void Chapter9::CV0_ErodingANDDilating(const string &str){
    Mat _m1 = imread(str,0);
    Mat _m2,_m3;
    Mat _m4 = Mat_<uchar>(_m1.size(),255) - _m1;
    //Mat b0 = (Mat_<uchar>(3,3)<<0,0,0,0,0,0,0,0,0);
    Mat b0 = (Mat_<uchar>(90,90,(uchar)1));
    Mat b1 = (Mat_<uchar>(_m1.size()/5,0));
    dilate(_m4,_m2,b0);
    erode(_m4,_m3,b0);
    for (size_t i = 0; i < _m4.rows; i++)
    {
        for (size_t j = 0; j < _m4.cols; j++)
        {
            if(_m4.at<uchar>(i,j)==0){
                cout<<"i="<<i<<",j="<<j<<endl;
                goto breakloop;
            }
        }
        
    }
    breakloop:for (size_t i = 0; i < _m4.rows; i++)
    {
        for (size_t j = 0; j < _m4.cols; j++)
        {
            if(_m3.at<uchar>(i,j)==0){
                cout<<"i="<<i<<",j="<<j<<endl;
                goto breakloop1;
            }
        }
        
    }
    
    breakloop1:imshow("原图",_m4);
    imshow("_m2",_m2);
    imshow("_m3",_m3);
   // imshow("_m21",_m4 - _m2);
    //imshow("_m22",_m2 - _m4);
}

void Chapter9::CV0_ErodingANDDilating2(){
    Mat _m1 = (Mat_<uchar>(9,9)<<1,1,1,1,1,1,1,1,1,
                                 1,1,1,1,1,1,1,1,1,
                                  1,1,1,0,0,1,1,1,1,
                                  1,1,1,0,0,1,1,1,1,
                                  1,1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,1);
    cout<<_m1<<endl;

    Mat b0 = (Mat_<uchar>(3,3)<<1,1,1,1,0,1,1,1,1);
    Mat b5 = (Mat_<uchar>(3,3)<<1,1,1,1,0,1,1,1,1);
    Mat b1 = (Mat_<uchar>(3,3,1));
    Mat b3 = (Mat_<uchar>(2,2,1));
    Mat b4 = (Mat_<uchar>(2,2,1));

    Mat _m2,_m3;
    erode(255*_m1,_m2,b0,Point(-1,-1),1,0,Scalar(255));
    erode(255*_m1,_m3,b1,Point(-1,-1),1,0,Scalar(255));
    //BorderTypes
    cout<<morphologyDefaultBorderValue()<<endl;
     
    cout<<cv::ocl::isOpenCLActivated()<<endl;
    cout<<_m2<<endl;
    cout<<_m3<<endl;
}