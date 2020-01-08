#include <string>
#include <iostream>
#include <list>
#include <vector>

//������Ի�ȡ������
#define  varName(x) #x
#define  printExp(exp) cout<<#exp<<"Ϊ:\t\t"<<(exp)<<endl  //�����ͷ�������ˣ�����һ������д����������

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
//string�Ĺ��췽��
void stringConstructor(){
    string str0;//�մ�
    string str1(5,'c');//����һ���ַ�������5��
    string str2(str1);//�����ַ���str1�ĸ���Ʒ��
    cout<<"str1_address="<<&str1<<" str1="+str1<<endl;
    cout<<"str2_address="<<&str2<<" str2="+str2<<endl;//�����ǲ�ͬ�������ڶ��������ַ���ָ��
    str1 = "xxxwww";
    cout<<"str1_address="<<&str1<<" str1="+str1<<endl;
    cout<<"str2_address="<<&str2<<" str2="+str2<<endl;
    string str3(str1,3);//���ַ���str1��ʼ��3��λ�õĲ�����Ϊ���캯���ĳ�ֵ,idx���㿪ʼ
    cout<<"str3="+str3<<endl;
    string str4(str1,2,2);//���ַ���str1��ʼ��idx1λ�õ��ҳ���Ϊ2�Ĳ�����Ϊ���캯���ĳ�ֵ,idx���㿪ʼ
    cout<<"str4="+str4<<endl;
    const char *Cstr0 ="xwxwxw";
    string str5(Cstr0);//��C_string���͵�cstr��Ϊ���캯���ĳ�ֵ
    cout<<"Cstr0="<<Cstr0<<endl;
    cout<<"str5="<<str5<<endl;
    string str6(Cstr0,2);
    cout<<"str6="+str6<<endl;
    try
    {
        // cout<<(int)'x'<<" "<<(int)'w'<<endl;
        // string str7(str1,'x','w');//���ｫ'x' 'w'ת��int���͵���ֵ��
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

    //����ʹ��list�ĵ�������ʼ��string,������ƥ��Ĺ��캯��
    // list<char> _list_char={'a','b','c'};
    // string str10(_list_char.begin(),_list_char.begin()+2);
    // cout<<"str10="<<str10<<endl;
    //ʹ��vector�ĵ��������Գ�ʼ��string
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
//string�Ĵ�С������
void stringCapacity(){
    
    //str.data()���ص����ַ����洢��ַ
    //����ÿ��str���·����ַ�����С��������ԭ��������
    //���¸������ַ���str�������ѷ���Ĵ�С��,��������·���Ĳ�����Ĭ�Ϸ����СΪ15
    string str1("stringstringstring");
    string str0("abcdefg");
    ShowStringContent(str1,"str1");
    ShowStringContent(str0,"str0");
    str1 = "stringstringstrings";
    ShowStringContent(str1,"str1");
    //�ռ�Ĵ�С��Ϊԭ����������������׵�ַû�б�
    //����ĵ�ַ�Ͷ����еİ������ַ������ַ��һ�£�
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
//�ַ���Ԫ�صķ���
void stringElementAcess(){
    string str0("abcdefg");
    try
    {
        
        showT(str0[0],"str0[0]=");
        //Խ��
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
    
    //ʹ�õ�����
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
//�ַ������޸�
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
        
        //������Ĳ���
        //s2.append({"str1qqqq","str"});
        //��������-initializer_list
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
}
//string����
void stringtest(){
    //�Զ���basic_string<T>
    //customize_basicstring::test();

    //string���캯��test����
    //stringoperator::stringConstructor();

    //string��С������
    //stringoperator::stringCapacity();
    //stringoperator::stringCapacity1();

    //stringԪ�ط���
    //stringElementAcess();
    
    //string�޸�
    stringModifiers();
}
}
#pragma endregion





#pragma region ����С����
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
        std::cerr << e.what() << '\n';
    }
    
    

}
    
    //cout<<str<<endl;
    system("pause");
    return 0;
}