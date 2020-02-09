#ifndef _utility_
#define _utility_
#include <string>
#include <iostream>
#define _var_(x) #x
#define showVar(x) showV((x),#x)
#define showContainerInfo(x) showContainer((x),#x)
#define showContainerContent(x) _showContainerContent(x,#x)
//��ʾ��������������
template<typename T> 
inline void showV(T a,const char *b){
    std::cout<<b<<":"<<a<<std::endl;
}

template<typename T>
inline void showContainer(T a,const char *b){
    std::cout<<"------------"<<b<<"------------"<<std::endl;
    showV(a.size(),"size()");
    //showV(a.capacity(),"capacity()");
    //showV(a.size(),"size()");
    std::cout<<"------------"<<b<<"------------"<<std::endl;
}

template<typename T>
inline void _showContainerContent(T a,const char *str){
    std::cout<<str<<":";
    if(a.size() == 0) {
        std::cout<<"��Ԫ��"<<std::endl;
        return;
    }
    for (auto i = a.begin();i != a.end(); i++)
    {
        std::cout<<*i<<",";
    }
    std::cout<<std::endl;
}
#endif
