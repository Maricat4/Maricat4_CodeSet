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
        string str0="index\t";
        for (size_t i = 0; i < size; i++)
        {
            
            str0 =str0+to_string(i)+"\t";
        }
        cout<<str0<<endl;
        cout<<"content\t";
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
        
        vector<int> v1{1,2,3,4};
        //front()
        showVar(v1.front());
        //at()
        showVar(v1.at(1));
        //operator[]
        showVar(v1[2]);
        //back()
        showVar(v1.back());

        void *p1 = v1.data();
        int *p2 = static_cast<int*>(p1);
        showVar(p2[0]);

        //iteraotr
        //beign() end()
        for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
        {
            showV("顺序迭代器",*i);
        }
        //iteraotr
        //rbegin() rend()
        for (vector<int>::reverse_iterator i = v1.rbegin(); i != v1.rend(); i++)
        {
            showV("反向迭代器",*i);
        }
        
    }

    void CapacityTest(){

        vector<char> v1;
        vector<int> v2{1,2,3,4};
        //empty()
        showVar(v1.empty());
        showVar(v2.empty());
        //size()
        showVar(v1.size());
        showVar(v2.size());
        //maxsize()        
        showVar(v1.max_size());
        showVar(v2.max_size());
        //reserve()
        showVar((long long)v2.data());
        v2.reserve(v2.size());
        showVar((long long)v2.data());  
        v2.reserve(v2.size()+1);      
        showVar((long long)v2.data());  
        //shrink_to_fit()
        v2.shrink_to_fit();
        showVar((long long)v2.data()); 
        showVar(v2.size());
        //capacity()
        showVar(v2.capacity());  
        v2.push_back(5);
        showVar(v2.capacity());

    }  

    void ModifiersTest(){
        vector<int> v1{1,2,3,4,5};
        vector<int> v2{'a','b','c','d'};

        //insert
        //1.single element
        int i1 = 6;
        v1.insert(v1.end(),i1);
        displayVectorContent(v1);
        //2.fill
        v1.insert(v1.end(),2,'a');
        displayVectorContent(v1);
        //3.range
        v1.insert(v1.end(),v2.begin()+1,v2.end());
        displayVectorContent(v1);
        //4.move
        v1.insert(v1.end(),7);
        displayVectorContent(v1);
        //5.initializer list
        v1.insert(v1.end(),{8,9,10});
        displayVectorContent(v1);

        cout<<"erase:"<<endl;
        //erase
        //1.single element
        showVar(*v1.erase(v1.cend()-2));
        displayVectorContent(v1);
        //2.range
        showVar(*v1.erase(v1.cbegin()+4,v1.cend()-1));
        displayVectorContent(v1);

        cout<<"emplace&&emplace_back:"<<endl;
        showVar(*v1.emplace(v1.begin(),89));
        displayVectorContent(v1);
        v1.emplace_back(99);
        displayVectorContent(v1);

        cout<<"push_back&&pop_back:"<<endl;
        showVar(sizeof(void*));
        showVar(sizeof(vector<int>));
        showVar((long long)v1.data());
        displayVectorContent(v1);
        v1.pop_back();
        showVar((long long)v1.data());
        displayVectorContent(v1);

        cout<<"resize:"<<endl;
        showVar((long long)v1.data());
        showVar(v1.size());
        showVar((long long)v1.data());
        v1.resize(v1.size()-1);
        showVar(v1.size());
        displayVectorContent(v1);
        v1.resize(v1.size()+1);
        displayVectorContent(v1);
        v1.resize(v1.size()+4,666);
        displayVectorContent(v1);


        cout<<"swap:"<<endl;
        vector<int> v3 = {1314};
        displayVectorContent(v3);
        v1.swap(v3);
        displayVectorContent(v1);
        displayVectorContent(v3);

        cout<<"clear:"<<endl;
        v1.clear();
        displayVectorContent(v1);
        showVar(*v1.end());
        showVar(v1.size());
        showVar(v1.capacity());
        v3.clear();
        displayVectorContent(v3);
        showVar(*v3.end());
        showVar(v3.size());
        showVar(v3.capacity());
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
        //vectorTest::ElementTest();
        //vectorTest::CapacityTest();
        vectorTest::ModifiersTest();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    system("pause");
    return 0;
}