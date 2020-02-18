#ifndef _utility_
#define _utility_
#include <string>
#include <list>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define INF 0x7fffffff
#define NINF 1<<31
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
//����ģ��ȫ�ػ�
typedef std::map<int,char> maptype1;
typedef std::map<int,int>  maptype2;
template<>
inline void _showContainerContent<maptype1>(maptype1 a,const char *str){
    std::cout<<str<<":";
    if(a.size() == 0) {
        std::cout<<"��Ԫ��"<<std::endl;
        return;
    }
    for (auto i = a.begin();i != a.end(); i++)
    {
        std::cout<<"("<<i->first<<","<<i->second<<")"<<",";
    }
    std::cout<<std::endl;
}
//����ģ��ȫ�ػ�
template<>
inline void _showContainerContent<maptype2>(maptype2 a,const char *str){
    std::cout<<str<<":";
    if(a.size() == 0) {
        std::cout<<"��Ԫ��"<<std::endl;
        return;
    }
    for (auto i = a.begin();i != a.end(); i++)
    {
        std::cout<<"("<<i->first<<","<<i->second<<")"<<",";
    }
    std::cout<<std::endl;
}
#endif
