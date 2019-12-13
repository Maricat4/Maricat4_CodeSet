#include <iostream>
using namespace std;

namespace xw{
template<typename T1,typename T2 = int>
void PR(T1 a,T2 b){
    cout<<"ver1:"<<(a+b)<<endl;
};

template<typename T2 = int>
void PR(float a,T2 b){
    cout<<"ver2:"<<a+(float)b<<endl;

};

template<class T1>
class point
{
    private:
        T1 a;
    public:
        ostream& operator<<(int b) const{
            return cout<<"ver2:"<<this<<endl;
        }   
};

template<class T1>
class point<T1*>
{
    private:
        T1 a;
    public:
        ostream& operator<<(int b) const{
            return cout<<"ver1:"<<this<<endl;
        }   
};
}

int main(){
    xw::PR(1,1);
    xw::PR(1.0f,1);

    xw::point<int*>()<<1;
    xw::point<int>()<<1;

    cout<<__cplusplus<<endl;
    return 0;
}