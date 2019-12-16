#include <string>
#include <iostream>
//typedef basic_string<int> intstring; 
using namespace std;
namespace customize_basicstring{
void test(){
    try
    {
        basic_string<int> str1 = {45,45,97,78,59};
        basic_string<int> str2 = {45,45,97,78,59};
        str1+=str2;
        for (size_t i = 0; i < str1.size(); i++)
        {
            cout<<str1[i]<<endl;
        }
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
}
namespace stringoperator{
//string的构造方法
void stringConstructor(){
    string str0;//空串
    string str1(5,'c');//生成一个字符串包含5个
    string str2(str1);//生成字符串str1的复制品。
    cout<<"str1_address="<<&str1<<" str1="+str1<<endl;
    cout<<"str2_address="<<&str2<<" str2="+str2<<endl;//对象是不同对象，由于对象中有字符串指针
    str1 = "xxxwww";
    cout<<"str1_address="<<&str1<<" str1="+str1<<endl;
    cout<<"str2_address="<<&str2<<" str2="+str2<<endl;
    string str3(str1,3);//将字符串str1中始于3的位置的部分作为构造函数的初值,idx从零开始
    cout<<"str3="+str3<<endl;
    string str4(str1,2,2);//将字符串str1中始于idx1位置的且长度为2的部分作为构造函数的初值,idx从零开始
    cout<<"str4="+str4<<endl;
    const char *Cstr0 ="xwxwxw";
    string str5(Cstr0);//以C_string类型的cstr作为构造函数的初值
    cout<<"Cstr0="<<Cstr0<<endl;
    cout<<"str5="<<str5<<endl;
    string str6(Cstr0,2);
    cout<<"str6="+str6<<endl;
    try
    {
        // cout<<(int)'x'<<" "<<(int)'w'<<endl;
        // string str7(str1,'x','w');//这里将'x' 'w'转成int类型的数值了
        // cout<<"str7="+str7<<endl;
        string str8(Cstr0,1,2);
        cout<<"str8="+str8<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    string str9(str1.begin(),str1.begin()+2);
    cout<<"str9="<<str9<<endl;
    
}
}
int main(){
    //customize_basicstring::test();
    stringoperator::stringConstructor();
    
    //cout<<str<<endl;
    system("pause");
    return 0;
}