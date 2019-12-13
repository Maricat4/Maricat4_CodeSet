#include <iostream>
using namespace std;
class Foo
{
private:
    int _id;
    long _data;
    string _str;
public:
    Foo():_id(0){
        cout<<"default ctor.this="<<this<<" id="<<_id<<endl;
    };
    Foo(int i):_id(i){
        cout<<"ctor.this="<<this<<" id="<<_id<<endl;
    };
    ~Foo(){
        cout<<"dtor.this="<<this<<" id="<<_id<<endl;
    };
    static void* operator new(size_t size);
    static void operator delete(void *pdead,size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void *pdead,size_t size);
};
void* Foo::operator new(size_t size){
     cout<<"member new[]"<<",size="<<size<<endl;
    cout<<"member new"<<endl;
    Foo *p = (Foo*)malloc(size);
    return p;
}
void Foo::operator delete(void *pdead,size_t size){
    cout<<"member delete"<<endl;
    free(pdead);
}
void* Foo::operator new[](size_t size){
     cout<<"member new[]"<<",size="<<size<<endl;
    Foo *p = (Foo*)malloc(size);
    return p;
}
void Foo::operator delete[](void *pdead,size_t size){
    cout<<"member delete[],"<<"pdead="<<pdead<<",size="<<size<<endl;
    free(pdead);
}

int main(){
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long)<<endl;
    cout<<sizeof(string)<<endl;
    cout<<sizeof(size_t)<<endl;
    Foo *pf = new Foo(2);
    delete pf;
    Foo *pf1 = ::new Foo;
    ::delete pf1;

    Foo *p = new Foo[5];
    delete[] p;
    system("pause");
    return 0;
}