#include <iostream>
#include <vector>
#include <string>
using namespace std;
//方便调试获取变量名
#define _var_(x) #x
#define showVar(x) showV(#x,(x))
using namespace std;
template<typename T,typename T1> 
inline void showV(T a,const T1 &b){
    cout<<a<<":"<<b<<endl;
}
template<typename T>
inline void display(T a,const char *b){
    cout<<b<<":"<<a<<endl;
}
// template<typename T>
// inline void display(T a,string b){
//     cout<<b<<":"<<a<<endl;
// }
namespace vectorTest{

    //显示确定大小的vector内容
    template<typename T>
    void _displayVectorContent(const vector<T> &test,const size_t &size){
        string str0;
        for (size_t i = 0; i < size; i++)
        {
            
            str0 =str0+to_string(i)+"\t";
        }
        cout<<str0<<endl;
        for (size_t i = 0; i < size; i++)
        {
            cout<<test.at(i)<<'\t';
        }
        cout<<endl;
    }



    //显示大小在20个以内的vector
    template<typename T>
    void displayVectorContent(const vector<T> &test){
        if(test.size()==0) return;
        cout<<"*************Vector Content*********"<<endl;
        string str0;
        if(test.size()<20){
            _displayVectorContent(test,test.size());
        }else{
            _displayVectorContent(test,20);
        }
        cout<<"*************Vector Content*********"<<endl;
    }
    

    template<typename T>
    void showVector(const vector<T> &test,const char *ch){
        cout<<"------------------------------------------"<<endl;
        cout<<ch<<" information:"<<endl;
        display(test.size(),"vector size:");
        display(test.capacity(),"vector capacity:");
        display((long long)test.data(),"data");
        displayVectorContent(test);
        display(sizeof(test),"type size");
        cout<<"-------------------------------------------"<<endl<<endl<<endl;
    }


    //构造函数、析构函数、赋值
    void initTest(){
        //default
        vector<int> v0;
        showVector(v0,_var_(v0));

        //fill
        vector<char> v1(10,'c');
        showVector(v1,_var_(v1));
        vector<char> v2(10);
        showVector(v2,_var_(v2));

        //range
        string str0("abcdefghjklmnopqrestuvwxyz");
        vector<int> v3(v1.begin(),v1.begin()+5);
        showVector(v3,_var_(v3));
        vector<char> v4(str0.begin(),str0.begin()+13);
        showVector(v4,_var_(v4));

        //copy
        vector<char> v5(v1);//需要值类型一致
        showVector(v5,_var_(v5));

        //move
        //右值引用

        //initializer list
        vector<int> v6{1,2,78,97,465,48,8,9};
        showVector(v6,_var_(v6));

        //sizeof是类型的大小
        cout<<"v6:"<<sizeof(int)<<endl;
        cout<<"void*:"<<sizeof(void *)<<endl;

    }

    void ElementTest(){
        //
    }
    
}


int main(){
    // vector<string> vecStr = {"hhh","aaa","bbbb","dddd"};
    // vector<string>::iterator iter = vecStr.begin();
    
    // for(;iter!=vecStr.end();iter++){
    //     cout<<*iter<<endl;
    // }
    // cout<<"hello world"<<endl;

    try
    {
        //vectorTest::initTest();
        vectorTest::ElementTest();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    system("pause");
    return 0;
}