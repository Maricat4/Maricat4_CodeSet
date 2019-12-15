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
    void stringConstructor(){
        
    }
}
int main(){
    customize_basicstring::test();
    
    
    //cout<<str<<endl;
    system("pause");
    return 0;
}