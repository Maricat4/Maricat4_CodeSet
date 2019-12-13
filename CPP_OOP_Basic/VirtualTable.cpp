#include <iostream>
using namespace std;

class Base0
{
public:
    int base1_1;
    int base1_2;
 
    //virtual void base1_fun1() {}
    //virtual void base1_fun2() {}
};
class Base1
{
public:
    int base1_1;
    int base1_2;
 
    virtual void base1_fun1() {}
    //virtual void base1_fun2() {}
};
class Base2
{
public:
    int base1_1;
    int base1_2;
 
    virtual void base1_fun1() {}
    virtual void base1_fun2() {}
};
int main(){
    Base0 b0;
    Base1 b1;
    Base2 b2;
    int a = sizeof(b0);
    int b = sizeof(b1);
    int c = sizeof(b2);
    cout<<__FILE__<<endl;
    cout<<__LINE__<<endl;
    cout<<a<<" "<<b<<" "<<c;
    system("pause");
    return 0;
}