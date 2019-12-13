#include <iostream>
namespace xw{
template<typename T>
class output{
    public:
    std::ostream& operator()(std::ostream &cout,const T& x) const{
        return cout<<x<<std::endl;
    }
    output(){
        std::cout<<this<<"i am coming"<<std::endl;
    }
    ~output(){
        std::cout<<"i am done"<<std::endl;
    }
};
template<typename T>
class output1{
    private:
    int a;
    public:
    std::ostream& operator()(std::ostream &cout,const T& x) const{
        return cout<<x<<std::endl;
    }
};

}
using namespace std;
int main(){
    xw::output<int>()(cout,50);
    xw::output<string>()(cout,"back home");
    xw::output<int>()(cout,sizeof(xw::output<long>));
    xw::output<int>()(cout,sizeof(xw::output1<long>));
    return 0;
}