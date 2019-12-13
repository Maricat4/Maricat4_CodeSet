#include <iostream>
#include <list>
using namespace std;

namespace xw{
    class DrawObject
    {
        public:
            virtual void Draw(){
                cout<<"this is a base"<<endl;
            };
    };
    class quad:public DrawObject{
        public:
            virtual void Draw(){
                cout<<"this is a quad"<<endl;
            }
    };

    class circle:public DrawObject{
        public:
            virtual void Draw(){
                cout<<"this is a circle"<<endl;
            }
    };


    class A{
        private:
            int m_data1,m_data2;
        public:
            int m_data4;
        public:
            A(int a,int b = 1):m_data1(a),m_data2(b){
                cout<<"A ctor"<<endl;
                m_data4 = 520;
            }
            virtual void vfunc1(){
                cout<<"A::vfunc1"<<endl;
            }
            virtual void vfunc2(){
                cout<<"A::vfunc2"<<endl;
            }
            void func1(){
                cout<<"A::func1"<<endl;
            }
            void func2(){
                cout<<"A::func2"<<endl;
            }
    };
    class B:public A{
        private:
            int m_data3;
        public:
            B(int a,int b = 1,int c = 5):m_data3(5),A(a,b){
                cout<<"B ctor"<<endl;
            }
            virtual void vfunc1(){
                cout<<"B::vfunc1"<<endl;
            }
            void func1(){
                cout<<"A::func1"<<endl;
            }
            void func2(){
                cout<<"B::func2"<<endl;
            }
    };
    class C:private B{
        private:
            int m_data1,m_data4;
        public:
            C(int a,int b = 1,int c = 2,int d = 4,int e = 5):B(a,b,c),m_data1(d),m_data4(e){
                cout<<"C ctor"<<endl;
            }
            virtual void vfunc1(){
                cout<<"C::vfunc1"<<endl;
            }
            void func2(){
                B::func2();
                cout<<"C::func2"<<endl;
                cout<<"C::m_data1:"<<m_data1<<endl;
                cout<<"C::m_data4:"<<m_data4<<endl;
                cout<<"A::m_data4:"<<A::m_data4<<endl;
                //cout<<"C::m_data2"<<B::m_data3<<endl;
                //cout<<"A::m_data1";
            }
    };
    class D:public A
    {
    private:    
    public:
        D():A(5){
            m_data4 = 20;
        }
        int m_data4;
    };
    
}
using namespace xw;
int main(){
    // list<xw::DrawObject*> a;
    // DrawObject a1;
    // quad a2;
    // circle a3;
    // a.push_back(&a1);
    // a.push_back(&a2);
    // a.push_back(&a3);
    // for(auto i:a){
    //     i->Draw();
    // }

    A a1(21,22);
    B b1(10,11,12);
    C c1(0,1,2,3,4);
    b1.func2();
    c1.func2();
    c1.vfunc1();
    D d1;
    cout<<d1.A::m_data4<<endl;
    //cout<<c1.A::m_data4<<endl;
    system("pause");
    // return 0;
}