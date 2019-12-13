#include <iostream>
#include "test.h"
using namespace std;
//extern const int bufsize;
#pragma region test1 测试复合与继承的析构与构造顺序
namespace test1{
class Component
{
private:

public:
    Component(/* args */);
    ~Component();
};

Component::Component(/* args */)
{
    cout<<"Component"<<endl;
}

Component::~Component()
{
    cout<<"component"<<endl;
}
class Base
{
private:
    
public:
    Base(/* args */);
    ~Base();
};

Base::Base(/* args */)
{
    cout<<"Base"<<endl;
}

Base::~Base()
{
    cout<<"base"<<endl;
}
class Derived:public Base
{
private:
    Component c1;
    int a;
public:
    Derived(/* args */);
    Derived(int x):a(x){
        cout<<"Derived"<<a<<endl;
    }
    ~Derived();
};

Derived::Derived(/* args */)
{
    cout<<"Derived"<<endl;
}

Derived::~Derived()
{
    cout<<"derived"<<a<<endl;
}
} 
#pragma endregion

#pragma region  test2 测试conversion转换函数
namespace test2{
class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    /* explict  */Fraction(int num,int den=1)
    :m_numerator(num),m_denominator(den){}
    // operator double() const{
    //     return (double)(m_numerator) / m_denominator;
    // }
    Fraction operator+(const Fraction& f){
        return Fraction(m_numerator+f._m_numerator(),m_denominator+f._m_denominator());
    }
    int _m_numerator() const{
        //m_numerator++;
        return m_numerator;
    }
    int _m_denominator() const{
        return m_denominator;
    }
};
}
#pragma endregion

// double operator+(test2::Fraction a,double b){
//     return (double)(a._m_numerator()) / a._m_denominator();
// }
void _test1(){
    test1::Derived d1(1);
    //test1::Derived d2(2);
}
void _test2(){
    test2::Fraction f(3,5);
    // double d2=f + 4;
    //test2::Fraction f2 = f+4;
    cout<<"f1:"<<f._m_numerator()<<"/"<<f._m_denominator()<<endl;
    // cout<<"d2:"<<d2<<endl;
   // cout<<"f2:"<<f2._m_numerator()<<"/"<<f2._m_denominator()<<endl;

}
int main(){
    _test1();
    // cout<<bufsize<<endl;
    // int static s = 5;
    // int p = 5;
    // int* const p1[] = {&s,&p};
    // cout<<"p1_address:"<<p1[0]<<","<<p1[1]<<endl;
    // cout<<"s:"<<s<<endl;
    // cout<<"*p1:"<<*p1[0]<<endl;
    // s++;
    // cout<<"p1_address:"<<p1[0]<<","<<p1[1]<<endl;
    // cout<<"s:"<<s<<endl;
    // cout<<"*p1:"<<*p1[0]<<endl;
    // cout<<s<<endl;
    // _test2();
    //system("pause");
    return 0;
}
