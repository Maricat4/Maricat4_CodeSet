#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<string> vecStr = {"hhh","aaa","bbbb","dddd"};
    vector<string>::iterator iter = vecStr.begin();
    
    for(;iter!=vecStr.end();iter++){
        cout<<*iter<<endl;
    }
    cout<<"hello world"<<endl;
    system("pause");
    return 0;
}