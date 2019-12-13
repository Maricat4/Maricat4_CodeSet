#include <iostream>
namespace xw{

template<typename T>
inline
std::ostream& operator<<(std::ostream &cout,T a){
    cout<<a<<std::endl;
    return cout;
}

template<class T1,class T2>
inline
double divide(T1 a,T2 b){
    return (double)a/(double)b;
}
}
//using namespace std;
int main(){
    int a = 45;
    int b = 67;
    float c = 90;
    std::cout<<a<<b<<std::endl;
    std::cout<<xw::divide(a,b)<<std::endl;
}