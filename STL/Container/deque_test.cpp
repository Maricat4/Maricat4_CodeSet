#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <Windows.h>
#include "utility.hpp"
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

namespace dequetest{
    void dequeInit(){
        //deque类型大小
        showVar(sizeof(deque<int>));
        showVar(sizeof(deque<double>));
        showVar(sizeof(int));
        showVar(sizeof(size_t));
        showVar(sizeof(float));
        showVar(sizeof(deque<int>::iterator));
        showVar(sizeof(vector<int>::iterator));
        deque<int> d1(1024,1);
        deque<int> d2(500,1);
        showContainerInfo(d1);
        showContainerInfo(d2);

        deque<int> v(1U<<29);  
        cout<<"step into stage one..."<<endl;  
        Sleep(300);  
        deque<int>().swap(v);  
        cout<<"step into stage two..."<<endl;  
        Sleep(300);    


    }
    //deque的构造，析构以及赋值
    void dequeInit1(){
        //构造函数
  
        //1.default
        deque<string> d1;
        showContainerContent(d1);
        //2.fill
        deque<int> d2(14);
        showContainerContent(d2);
        deque<string> d3(14);
        showContainerContent(d3);
        //3.ininitializerlist
        deque<string> d4{"love","peace","war"};
        showContainerContent(d4);
        //4.range
        deque<string> d5(d4.begin(),d4.end()-1);
        showContainerContent(d5);
        //5.move
        deque<string> d6 = std::move(d4);
        showContainerContent(d4);
        showContainerContent(d6);
        //6.copy
        deque<string> d7(d5);
        showContainerContent(d7);
        
    
        //deque<int>::iterator
        //销毁
        d7.clear();
        d7.shrink_to_fit();
        //showContainerContent(d7);
        //copy=
        deque<string> d8;
        d8 = d6;
        showContainerContent(d8);
        //move=
        d8 = std::move(d5);
        showContainerContent(d5);
        showContainerContent(d8);
        //initializerlist
        d8 = {"love","you","3000","times"};
        showContainerContent(d8);   
    }

    void testAcess(){

        //iterator and reverse iterator
        deque<int> d1 = {1,2,3,4,5,6,7,8,9};
        showContainerContent(d1);
        //front and back
        d1.front()+=23;
        d1.back()-=23;
        for (auto i = d1.begin(); i !=  d1.end(); i++)
        {
            *i += 2;
        }
        showContainerContent(d1);
        cout<<"acess by reverse_iterato:";
        for (auto i = d1.rbegin(); i != d1.rend(); i++)
        {
            cout<<*i<<",";
        }
        cout<<endl;
        
        //acess by at、[]
        for (size_t i = 0; i < d1.size(); i++)
        {
            d1[i] -= 2;
        }
        showContainerContent(d1);
        for (size_t i = 0; i < d1.size(); i++)
        {
            d1.at(i) += 3;
        }
        showContainerContent(d1);
        

    }
    void testCapacity(){
        deque<int> d1 = {1,2,3,4,5,6,7,8,9};
        showVar(d1.size());
        showVar(d1.max_size());
        showVar(deque<string>().max_size());
        deque<int> d2 = {1};
        if(!d2.empty()){
            d2.swap(d1);
        }
        showContainerContent(d1);
        showContainerContent(d2);
        d1.clear();
        d1.shrink_to_fit();
        if (d1.empty())
        {
            cout<<"d1 is empty"<<endl;
        }
        
    }
    void testModifiers(){
        //对于clear内存释放的测试
    //     auto t1 = clock();
    //     deque<int> d1(1U<<26); 
    //     auto t2 = clock();
    //     showVar(t2-t1);
    //     t1 = clock();
    //     d1.clear();
    //     t2 = clock();
    //    showVar(t2-t1);
    //     d1.shrink_to_fit();


        //insert
        deque<int> d1 = {1,2,3,4,5,6,7,8,9,10};
        //single element
        d1.insert(d1.begin(),0);
        showContainerContent(d1);
        //fill element
        d1.insert(d1.end(),5,20);
        showContainerContent(d1);
        int a[] = {11,1,12,3,4,5};
        deque<string> d2 = {"love","you","3000"};
        //range insert
        d1.insert(d1.begin()+5,a,a+4);
        showContainerContent(d1);

        //emplace、emplace_back、emplace_front
        d1.emplace(d1.begin()+1,-12);
        d1.emplace_back(-90);
        d1.emplace_front(-45);
        showContainerContent(d1);

        //push_back、push_front
        //pop_back、pop_front
        d1.push_back(1<<31);
        d1.push_front(0xfffffff);
        showContainerContent(d1);

        d1.pop_back();
        d1.pop_front();
        showContainerContent(d1);


        //erase
        //single
        d1.erase(find(d1.begin(),d1.end(),-90));
        //range
        showContainerContent(d1);
        d1.erase(d1.begin(),d1.begin()+5);
        showContainerContent(d1);
        //reverse range error 没有参数匹配的函数
        //d1.erase(d1.rbegin(),d1.rbegin()+5);

        //resize
        //n<d1.size()
        d1.resize(d1.size()-6);
        showContainerContent(d1);
        d1.resize(d1.size()+6,20);
        showContainerContent(d1);

        //vector resize()
        vector<int> v1 = {1,2,3};
        v1.resize(1);
        showContainerContent(v1);
        v1.resize(3,3);
        showContainerContent(v1);
        
        deque<int> d3 = {1};
        d1.swap(d3);
        showContainerContent(d1);
        showContainerContent(d3);
        
        //d1.swap((deque<int>){1,2,3});
        //showContainerContent(d1);
        //d1.insert(d1.begin(),d2.begin(),d2.end());
        // vector<int> a1(1U<<18,0);
        // showVar(a1.capacity());
        // a1.clear();
        // showVar(a1.capacity());
    }

}

int main(){
    try
    {
        //dequetest::dequeInit();
        //dequetest::dequeInit1();
        //dequetest::testAcess();
        //dequetest::testCapacity();
        dequetest::testModifiers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    system("pause");
    return 0;
}