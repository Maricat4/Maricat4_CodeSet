#include <iostream>
#include<string>
#include<vector>
#include <cstring>
using namespace std;
class STR
{
private:
    char * m_data;
public:
    STR(const char *str);
    STR(const STR & str);
    STR& operator=(const STR &str);
    ~STR();
};
//构造函数既可以在函数定义出指定默认参数，又可以在函数声明出指定默认参数，但不能同时指定默认参数
inline
STR::STR(const char *str=0)
{
    if(str){
        m_data = new char[strlen(str)+1];
        strcpy(m_data,str);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    cout<<"STR"<<endl;
}
inline
STR::STR(const STR & str)
{
    
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
    cout<<"copy ctor+"<<m_data<<endl;
}
inline
STR& STR::operator=(const STR &str)
{
    if(this == &str){
        cout<<"same object"<<endl;
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
    cout<<"operator="<<endl;
    return *this;
}
STR::~STR()
{
    cout<<m_data<<"+deconstructor"<<endl;
    delete[] m_data;
}
void test(){
    STR s1("1");//通过const char* 构造
    // STR s2("2");//拷贝构造
    // STR s3("3");

    STR s5 = "12345";
    //STR s6 = 'a';
    STR s4 = s1;//调用了拷贝构造
    cout<<(long long)&s1<<endl;
    cout<<(long long)&s5<<endl;
    cout<<(long long)&s4<<endl;
    
    // s3 = s3;
    // s3 = s2;
}
int main(){
    test();
    cout<<sizeof(void*)<<endl;
    system("pause");
    return 0;
}