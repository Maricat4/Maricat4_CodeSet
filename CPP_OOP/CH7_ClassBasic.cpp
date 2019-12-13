#include <iostream>
using namespace std;

int ivar1 = 1<<31;
#pragma region 友元与const成员重载
namespace xw{

class A
{
    friend void displayA(A& a){
        cout<<"friend"<<endl;
        cout<<a.a<<endl;
    }
private:
    int a{9};
    //A b;
    void do_dispaly(ostream &os) const{
        os<<a<<endl;
    }
public:
    int b = 50;
    using str = string;
    A(int t = 10):a(t){}
    A& display(ostream &os){
        os<<"unconst:";
        do_dispaly(os);
        return *this;
    }
    
    const A& display(ostream &os) const{
        os<<"const:";
        do_dispaly(os);
        return *this;
    }
};
void displayA(A& a);   
}
#pragma endregion

#pragma region 类型名的特殊处理
namespace xw1{
//typename double d;
typedef int i;
class A
{
private:
    //d d_1;
    i i1;
public:
    A(i h):i1(h){};
    i returni1(){return i1;};
    typedef int i;
};
}
#pragma endregion

#pragma region 成员定义中的普通块作用域的名字查找
namespace xw2{
int ivar1 = 0X7ffffff;
class A
{
private:
    int ivar;
public:
    A(int a = 10):ivar(a){};
    int display(int ivar){
        cout<<ivar<<endl;
        cout<<(*this).ivar<<endl;
        cout<<A::ivar<<endl;
        cout<<::ivar1<<endl;
        return ivar;
    }
};

}


#pragma endregion
//using namespace xw;

#pragma region 使用输入流作为参数作为构造函数
namespace xw3{

class A
{
    friend ostream& operator<<(ostream &c,const A& rhs);
private:
    string str;
public:
    explicit A(string s):str(s){};
    A(istream &is = cin){read(is,*this);};
    istream & read(istream & is, A &rhs)
    {
        is >> rhs.str;
        return is;
    }
    
};
ostream& operator<<(ostream &c,const A& rhs){
    c<<rhs.str;
    return c;
}
}


#pragma endregion
#include<vector>
#pragma region 无初始化的类
namespace xw4{
class classA
{
private:
    int a;
public:
    classA(int i = 45):a(i){};

};

class A
{
private:
    int a;
    classA ca;
public:
    //A(int i):a(i){};
    void show(){
        cout<<a<<",";
    }
};
class B
{
private:
    int a;
public:
    B(int i = 1):a(i){};
    void show(){
        cout<<a<<",";
    }
};
//vector<A> vec_a(10);
vector<B> vec_b(10);
}
#pragma endregion

#pragma region 聚合类

#pragma endregion

#pragma region 静态成员的定义与使用
namespace xw5{
class A
{
private:
    const static int a = 5;
    static int c;
    int b = 5;
public:
    A(int i = 0):b(i){};
};
int A::c = 5;

}
#pragma endregion
struct data{
    int a;
    int b;
    int c;
};

namespace xw6{
    class A
    {
    private:
        string _str;
    public:
        A(string str):_str(str){}
        A& combine(const A &a){
            _str+=a._str;
            return *this;
        }
        void show() const{
            cout<<_str<<endl;
        }
    };
   
    
}
int main(){
    xw::A a(100);
    const xw::A b(10);
    a.display(cout);
    b.display(cout);
    displayA(a);
    xw::A::str k("love");
    cout<<k<<endl;

    xw2::A a2(50);
    a2.display(20);

    // xw3::A xw3_A;
    // cout<<xw3_A<<endl;

    int arr[9] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     xw4::vec_a[i].show();
    // }
    for (int i = 0; i < 10; i++)
    {
        xw4::vec_b[i].show();
    }
    cout<<endl;
    xw4::A xw4_a;
    xw4_a.show();
    cout<<endl;

    xw3::A xw3_a=(xw3::A)"cins";
    string str_a = "ssss";
    char ch_a[] = "xiuxiu";
    xw3::A xw3_b("jijji");
    xw3::A xw3_c(str_a);
    xw3::A xw3_d(ch_a);
    cout<<xw3_a<<endl;
    cout<<xw3_b<<endl;
    cout<<xw3_c<<endl;
    cout<<xw3_d<<endl;

    char ch_b[3] ={'a','a','a'};
    
    cout<<(string)ch_b<<endl;
    cout<<sizeof((string)ch_b)<<endl;

    data data_a = {4,5,6};

    xw6::A xw6_a("love");
    xw6_a.combine("you");
    xw6_a.show();
    system("pause");
    return 0;
}