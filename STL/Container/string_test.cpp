#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
//方便调试获取变量名
#define showVar(x) showV(#x,(x))
template<typename T,typename T1> 
inline void showV(T a,const T1 &b){
    cout<<a<<":"<<b<<endl;
}
template<typename T>
inline void showT(T a,const string &b = "output:"){
    cout<<b<<a<<endl;
}
//typedef basic_string<int> intstring; 
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
    //空字符串大小为1
    string str0;
    cout<<sizeof(*str0.data())<<endl;
    showT(str0);
    string str1("operating system");
    showVar(str1);
    showVar(str1.size());
    str1.resize(str1.size()-5);
    showVar(str1);
    showVar(str1.size());
    str1.resize(str1.size()+5);
    showVar(str1);
    showVar(str1.size());
    str1.resize(str1.size()+5,'R');
    showVar(str1);
    showVar(str1.size());
    str1.assign(32,'c');
    showVar(str1);
    showVar(str1.capacity());
    str1.reserve(31);
    showVar(str1);
    showVar(str1.capacity());
    str1.reserve(33);
    showVar(str1);
    showVar(str1.capacity());

    str1.clear();
    showVar(str1.size());
    showVar(str1.capacity());
    str1.assign(86,'s');
    showVar(str1);
    showVar(str1.size());
    showVar(str1.capacity());
    str1.shrink_to_fit();
    showVar(str1);
    showVar(str1.size());
    showVar(str1.capacity());

    string str2("aaaaaaaaaaaaaaaaaaaaaaaaa");
    showVar(str2);
    showVar(str2.size());
    showVar(str2.capacity());
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
    string s2("append");
    s0+='a';
    s0+=s1;
    s0+="ccc";
    //s0+={26,26,26};
    showT(s0,"s0=");

    
    s2.append(string("str+"));
    s2.append(string("str+"),0,1);
    s2.append("cstr+");
    s2.append("cstr+",4);
    s2.append(3,'f');
    s2.append(s0.begin(),s0.end());
    try
    {
        
        //有问题的操作
        //s2.append({"str1qqqq","str"});
        //正常操作-initializer_list
        s2.append({'a','a','x'});
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    showT(s2,"s2=");

    //push_back
    s0.push_back('z');
    showT(s0,"s0(push_back(z))=");
    //pop_back
    s0.pop_back();
    showT(s0,"s0(pop_back)=");
    cout<<(long long)s0.data()<<endl;
    cout<<(long long)s1.data()<<endl;
    cout<<(long long)s2.data()<<endl;
    s0.assign(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    cout<<(long long)s0.data()<<endl;

    //insert
    string s3("dio");
    s3.insert(3,"dio");
    showT(s3,"s3:");
    s3.insert(s3.end()-3,{'j','o','j','o'});
    showT(s3,"s3:");
    s3.insert(s3.end()-3,100,'B');
    showT(s3,"s3:");


    //erase
    s3.erase(s3.end()-3-100,s3.end());
    showT(s3,"s3:");
    s3.erase(0,1);
    showT(s3.length());
    showT(s3,"s3:");
    s3.erase(s3.begin(),s3.begin()+1);
    showT(s3,"s3:");
    showT(s3.length());

    //replace
    showT(s3,"s3:");
    s3.replace(2,0,"DIODA");
    showT(s3,"s3:");
    s3.erase(s3.find("DIODA"),5);
    showT(s3,"s3:");
    s3.replace(s3.begin(),s3.begin(),"DIODA");
    showT(s3,"s3:");
    s3.erase(s3.find("DIODA"),5);
    showT(s3,"s3:");
    s3.replace(0,0,"DIODA",0,3);
    showT(s3,"s3:");
    s3.replace(0,0,"DA",2);

    //swap
    string s4(5,'k');
    showT(s4,"s4:");
    showT((long long)s4.data(),"s4.data:");
    showT((long long)s3.data(),"s3.data:");
    showT(s3+" "+s4,"s3&s4:");
    s3.swap(s4);
    showT((long long)s4.data(),"s4.data:");
    showT((long long)s3.data(),"s3.data:");
    showT(s3+" "+s4,"s3&s4:");
    swap(s3,s4);
    showT((long long)s4.data(),"s4.data:");
    showT((long long)s3.data(),"s3.data:");
}

//字符串操作
void stringOperation(){
    //compare
    string s0("f");
    string s1("d");
    showVar(s0);
    showVar(s1);
    showVar(s0.compare(s1));
    string s2;
    showVar(s0.compare(s2));

    string s3("this is a adventure of finding");
    showVar(s3.find("b"));
    showVar(s3.npos);
    showVar(s3.find("abbb",1,2));
    showVar(s3.rfind('i'));
    showVar(s3.find_first_of("mnb"));
    int found = 0;
    found=s3.find_first_of("shit");
    while (found!=string::npos)
    {
        s3.at(found)='*';
        found=s3.find_first_of("shit");
    }
    showVar(s3);

}

void stringIO(){
    string s0("abcdefg");
    ShowStringContent(s0,"s0");
    showVar(s0.c_str());
    showVar(s0.data());

    char *s1 = (char *)malloc(5*sizeof(char));
    char s5[] = "ss";
    char *s2 = "ssssss";
    char *s3 = "ssssss1";
    const char *s4 = "asfeg";
    string s6("DNM");
    showVar((long long)s1);
    showVar((long long)s2);
    showVar((long long)s3);
    showVar((long long)s4);
    showVar((long long)s5);
    showVar((long long)&s6);
    char const *p = "asss";
    s0.copy(s1,3,0);
    s1[2]='\0';
    showVar(s1);
    free(s1);
    showVar(s0.substr());
    showVar(s0.substr(0,4));

    cin>>s0;
    showVar(s0);
    //cin并非直接从输入中读数据，而是从缓冲区读数据，如果缓冲仍然有数据，便会直接读入。cin.clear的
    cin.sync();
    cin.clear();
    getline(cin,s0);
    showVar(s0);
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
    //stringElementAcess();
    
    //string修改
    //stringModifiers();

    //string操作
    //stringOperation();

    //stringIO以及其他函数
    stringIO();
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
    try
    {
        stringoperator::stringtest();
    }
    catch(const std::exception& e)
    {
        std::cerr <<"error:"<< e.what() << '\n';
    }
    
    

}
    
    //cout<<str<<endl;
    system("pause");
    return 0;
}