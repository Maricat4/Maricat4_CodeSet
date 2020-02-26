#include <iostream>
#include <tuple>
using namespace std;

int main(){
    tuple<int,string> a(1,"aaa");
    cout<<get<0>(a)<<endl;
    cout<<get<1>(a)<<endl;
    system("pause");
    return 0;
}