#include <iostream>
using namespace std;
namespace xw{
template<typename T>
struct output{

};
template<>
struct output<int>{
    ostream& operator<<(int x) const
    {  
        return cout<<x*10<<endl;
    }
};
template<>
struct output<string>{
    ostream& operator<<(string x) const
    {  
        return cout<<x<<endl;
    }
};
template<>
struct output<double>{
    ostream& operator<<(double x) const
    {  
        return cout<<x<<endl;
    }
};
}

int main(){
    xw::output<string>()<<"Star Platinum";
    xw::output<int>()<<5;
    xw::output<double>()<<5.3;
    return 0;
}