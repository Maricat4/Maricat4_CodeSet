#include "utility.hpp"
#include <functional>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,9,20};
    find(a,a+10,20);
    //errro
    //count(a+10,a,9);
    //cout<<count_if(a,a+11,not1(bind<int>(less<int>(),std::placeholders::_1,5)))<<endl;
    auto f1 = bind(less<int>(),placeholders::_1,10);
    try
    {
        for_each(a,a+9,f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    // vector<int> v1(a,a+10);

    // iterator_traits<int*>::value_type a1;
    // iterator_traits<vector<int>::iterator>::value_type a2;
    // cout<<is_void<int>::value<<endl;
    //__false_type
    system("pause");
    
    return 0;

}