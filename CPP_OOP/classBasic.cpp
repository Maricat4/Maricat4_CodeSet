#include <iostream>
using namespace std;

namespace xw{
class classBasic
{
private:
    int A_data;
public:
    classBasic(int a):A_data(a){}
};
}
using namespace xw;
int main(){
    classBasic A;
    return 0;
} 