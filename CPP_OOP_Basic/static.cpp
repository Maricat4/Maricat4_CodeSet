#include <iostream>
using namespace std;
class A
{
private:
    /* data */
    //static int a;
public:
    static A& getInstance();
    static void show();
    static int b;
    A(/* args */);
    ~A();
};
int A::b=8;
A::A(/* args */)
{
}

A::~A()
{
}

A& A::getInstance(){
    static A a;
    cout<<&a<<endl;
    return a;
}
void A::show(){
    cout<<b<<" "<<&b<<endl;
}
int& set(){
    static int a;
    a++;
    cout<<a<<" "<<&a<<endl;
    return a;
}
int main(){
    //A::getInstance();
   // A::getInstance();
    //set()=5;
    //A::a=8;
    set();
    //a = 6;
    set();
    A::show();
    A::show();
    char s[8]="hello";
    cout<<(long)&s[1]<<endl;
    cout<<(long)&s[2]<<endl;
    system("pause");
    return 0;
}