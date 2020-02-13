#include "utility.hpp"
using namespace std;
 struct empty1{
    alignas(size_t) unsigned char a;
};
namespace listTest{
    size_t operator-(list<int>::iterator it1,list<int>::iterator it2){
        int i = 0;
        for(;it1!=it2;it1++){
            ++i;
        }
        return i;
    }
    list<int>::iterator& operator+(list<int>::iterator &it1,int &&i){
        for (size_t j = 0; j<i; it1++,j++);
        return it1;
    }
    list<int>::iterator operator+(list<int>::iterator &&it1,int &&i){
        for (size_t j = 0; j<i; it1++,j++);
        return it1;
    }
    void listinit(){
        //类型大小
        showVar(sizeof(list<int>));

        alignas(size_t) int a;
        showVar(sizeof(int));
        showVar(sizeof(a));
        showVar(sizeof(empty1));

        //构造函数 
        //1.default
        list<string> d1;
        showContainerContent(d1);
        //2.fill
        list<int> d2(14);
        showContainerContent(d2);
        list<string> d3(14);
        showContainerContent(d3);
        //3.ininitializerlist
        list<string> d4{"love","peace","war"};
        showContainerContent(d4);
        //4.range
        list<string> d5(d4.begin(),d4.end());
        showContainerContent(d5);
        //5.move
        list<string> d6 = std::move(d4);
        showContainerContent(d4);
        showContainerContent(d6);
        //6.copy
        list<string> d7(d5);
        showContainerContent(d7);
    }

    void elementAcessTest(){
        //by iterator
        list<int> l1{1,2,3,4,5,6,7};
        for (auto i = l1.begin(); i != l1.end(); i++)
        {
            *i +=1;
        }
        showContainerContent(l1);
        //front,back
        showVar(l1.front());
        showVar(l1.back());
        //无匹配的运算符
        //auto it1 = l1.begin()+2;

        //end()++后回到begin()
        auto it1 = l1.end();
        ++it1;
        showVar(*it1);
        
    }
    void modifierTest(){
        list<int> l1;
        //push_back,emplace_back,emplace_front
        l1.push_back(1);
        l1.emplace(l1.begin(),2);
        l1.emplace_back(3);
        l1.emplace_front(4);
        showContainerContent(l1);


        //insert
        //insert 插入的位置是position之前
        //1.insert single element,修正这里是move 
        auto it1 = l1.insert(++l1.begin(),-1);
        //2.insert fill 
        auto it2 = l1.insert(--l1.end(),5,-8);
        showContainerContent(l1);
        //clear 会析构其他元素
        l1.clear();
        it1 = ++l1.begin();
        showVar(*it1);
        showVar(l1.begin()==(++l1.begin()));
        l1.assign({1,2,3,4,5,6,7,8});
        it1 = l1.begin();
        //3.insert initializer list
        it1 = l1.insert(it1 + 5,{33,33,33});
        showContainerContent(l1);
        vector<int> v1 = {3,2,1,0,-1,-2};
        //4.insert range
        it1 = l1.insert(it1,v1.begin(),v1.end());
        showContainerContent(l1);
        //5.insert single element
        int _i1 = 1<<31;
        l1.insert(it1,_i1);
        showContainerContent(l1);
        // showVar(5-6);
        // showVar(l1.begin() - l1.end());
        // showVar(l1.size());

        //resize()
        showVar(l1.size());
        l1.resize(1);
        showContainerContent(l1);
        l1.resize(2);
        showContainerContent(l1);




    }
    struct funCompare{
        bool operator()(int a,int b){
            return abs(a) < abs(b) ;
        }
    };
      bool comparePointer(int a,int b){
            return abs(a) < abs(b) ;
        }
    void operationTest(){
        list<int> a = {0,-1,-2,1,2};
        //sort
        showContainerContent(a);
        a.sort();
        showContainerContent(a);
        a.sort(funCompare());
        showContainerContent(a);
        a.sort();
        showContainerContent(a);
        a.sort(comparePointer);
        showContainerContent(a);
        a.sort();
        //merge，如果让它合并未排好序的链表会怎么样,
        //  
        list<int> b = {4,5,-4,-5,1<<30};
        list<int> c = {14,-15,16,-47};
        a.sort(funCompare());b.sort(funCompare());
        a.merge(b,comparePointer);
        showContainerContent(a);
        b.sort();c.sort();
        b.merge(c);
        showContainerContent(b);
        b.merge({1,2,3,4,5});
        showContainerContent(b);

        //splice 单纯拼接，无排序，需要指定在哪里开始拼接
        b.splice(b.begin() + 2 ,{10,10});
        showContainerContent(b);

        b.reverse();
        showContainerContent(b);

        b.remove_if([](int a){return a > 0;});
        showContainerContent(b);

        showContainerContent(a);
        a.unique([](int a,int b){return abs(a) == abs(b);});
        showContainerContent(a);

    }
}

int main(){

    try
    {
        //listTest::listinit();
        //listTest::elementAcessTest();
        //listTest::modifierTest();
        listTest::operationTest();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       
    system("pause");
}
