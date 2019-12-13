#include <iostream>

namespace xw{
template<typename T>
class shared_ptr
{
private:
    T* px;
public:
    shared_ptr(T* p):px(p){};
    //~shared_ptr();
    T& operator*() const{return *px;}
    T* operator->() const{return px;}
};

struct point{
    private:
    int x;
    int y;
    public:
    point(int a,int b):x(a),y(b){};
    void showpoint() const {
        std::cout<<x<<","<<y<<std::endl;
    }
};
}
using namespace std;
//using namespace xw;

int main(){
    int a=19,*p = &a;
    xw::shared_ptr<int> p1(p);
    xw::point p2(40,63);
    xw::shared_ptr<xw::point> p3(&p2);
    cout<<*p1<<endl;
    p3->showpoint();
    return 0;
}