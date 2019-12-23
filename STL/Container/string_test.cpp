#include <string>
#include <iostream>
#include <list>
#include <vector>

//方便调试获取变量名
#define  varName(x) #x
#define  printExp(exp) cout<<#exp<<"为:\t\t"<<(exp)<<endl  //这样就方便调试了，不用一个个的写变量名称了

//typedef basic_string<int> intstring; 
using namespace std;
template<typename T>
inline void showT(T a,const string &b = "output:"){
    cout<<b<<a<<endl;
}
#pragma region customize
namespace customize{
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
#pragma endregion

#pragma region string
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

    //尝试使用list的迭代器初始化string,报错无匹配的构造函数
    // list<char> _list_char={'a','b','c'};
    // string str10(_list_char.begin(),_list_char.begin()+2);
    // cout<<"str10="<<str10<<endl;
    //使用vector的迭代器可以初始化string
    vector<char> _vector_char={'a','b','c'};
    string str11(_vector_char.begin(),_vector_char.begin()+2);
    cout<<"str11="<<str11<<endl;
    
}
void ShowStringContent(const string &str,const string &name){
    cout<<name<<":"<<str<<endl;
    cout<<name<<" address:"<<(long long)&str<<endl;
    cout<<name<<" data() address:"<<(long long)str.data()<<endl;
    cout<<name<<" size()="<<str.size()<<endl;
    cout<<name<<" length()="<<str.length()<<endl;
    cout<<name<<" capacity()="<<str.capacity()<<endl;
}
void ShowCharStar(const char  *str,const string &name){
    cout<<name<<":"<<str<<endl;
    cout<<name<<" address:"<<(long long)str<<endl;
}
//string的大小与容量
void stringCapacity(){
    
    //str.data()返回的是字符串存储地址
    //并且每次str重新分配字符串大小，并且是原来的两倍
    //重新赋给的字符串str比现在已分配的大小大,会造成重新分配的操作，默认分配大小为15
    string str1("stringstringstring");
    string str0("abcdefg");
    ShowStringContent(str1,"str1");
    ShowStringContent(str0,"str0");
    str1 = "stringstringstrings";
    ShowStringContent(str1,"str1");
    //空间的大小变为原来的两倍，对象的首地址没有变
    //对象的地址和对象中的包含的字符数组地址不一致？
    const char *p1 = str1.data();
    ShowCharStar(p1,"p1");
    str1 = "str1";
    ShowCharStar(p1,"p1");
    ShowStringContent(str1,"str1");

}
void stringCapacity1(){
    string str0;
    cout<<sizeof(*str0.data())<<endl;
    showT(str0);
}
//字符串元素的访问
void stringElementAcess(){
    string str0("abcdefg");
    try
    {
        
        showT(str0[0],"str0[0]=");
        //越界
        showT(str0[str0.size()],"str0[str0.size()]=");
        showT(str0.at(1),"str0.at(1)=");
        
        showT(str0.back(),"str0.back=");
        showT(str0.front(),"str0.front=");
        //showT(str0.at(str0.size()),"str0.at(str0.size())=");
        //showT(str0.at(-1),"str0.at(str0.size())=");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //使用迭代器
    string::iterator it = str0.begin();
    *it = 'b';
    for (; it<str0.end(); ++it)
    {
        cout<<*it<<",";
    }
    cout<<endl;
    string::const_iterator it1 = str0.cbegin();
    //*it1 = 'a';
    for (; it1!=str0.end(); ++it1)
    {
        cout<<*it1<<",";
    }
    cout<<endl;
    string::reverse_iterator it2 = str0.rbegin();
    for (; it2!=str0.rend(); ++it2)
    {
        cout<<*it2<<",";
    }
}
//字符串的修改
void stringModifiers(){
    string s0("inf");
    string s1(2,'b');
    s0+='a';
    s0+=s1;
    s0+="ccc";
    s0+={'d','d','d'};
    showT(s0,"s0=");
    
}
//string测试
void stringtest(){
    //自定义basic_string<T>
    //customize_basicstring::test();

    //string构造函数test函数
    //stringoperator::stringConstructor();

    //string大小与容量
    //stringoperator::stringCapacity();
    //stringoperator::stringCapacity1();

    //string元素访问
    stringElementAcess();
}
}
#pragma endregion





#pragma region 各类小测试
namespace tests{
//testClassSize
#pragma region testClassSize
class A{
const static int a = 7;
private:
    char *str;
};
//int A::a = 7;
void test0(){
    cout<<"A="<<sizeof(A)<<endl;
    cout<<"A="<<sizeof(A*)<<endl;
    cout<<"A="<<sizeof(string)<<endl;
    cout<<"A="<<sizeof(int)<<endl;
}
#pragma endregion

}

#pragma endregion
int main(){
{
    stringoperator::stringtest();

}
    
    //cout<<str<<endl;
    system("pause");
    return 0;
}