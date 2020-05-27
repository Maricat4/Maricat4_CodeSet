/*
STL中的堆操作以及优先队列的使用
*/
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#define _GLIBCXX_DEBUG
using namespace std;

template<typename T>
inline void showContainer(T a){
    for(auto i : a){
        cout<<i<<",";
    }
    cout<<endl;
}
int main(){
    vector<int> v1 = {21,42,36,4,57,6,7,77,99};

    cout<<"v1是否为堆："<<is_heap(v1.begin(),v1.end())<<endl;
    cout<<"v1堆最大长度："<<distance(v1.begin(),is_heap_until(v1.begin(),v1.end()))<<endl;
    //默认为大根堆
    //[v1.begin(),v1.end()-1)之间建堆
    make_heap(v1.begin(),v1.end()-1);
    showContainer(v1);
    //压入尾元素
    push_heap(v1.begin(),v1.end());
    showContainer(v1);
    //将栈顶元素放入最后一个位置
    pop_heap(v1.begin(),v1.end());
    showContainer(v1);
    //排序，默认大根堆，从小到大排序
    sort_heap(v1.begin(),v1.end()-1);
    showContainer(v1);

    v1 = {21,42,36,4,57,6,7,77,99};
    //小根堆,指定比较函数
    make_heap(v1.begin(),v1.end(),greater<int>());
    showContainer(v1);

    //排序，从大到小排序
    sort_heap(v1.begin(),v1.end(),greater<int>());
    showContainer(v1);

    //优先队列,默认最大堆，大根堆，最大优先
    //v1 = {21,42,36,4,57,6,7,77,99};
    v1 = {21,42,36,4,57,6,7,77,99};
    priority_queue<int> v2(v1.begin(),v1.end());
    cout<<v2.top()<<endl;
    while(!v2.empty()){
        cout<<v2.top()<<",";
        v2.pop();   
    }
    
    return 0;
}