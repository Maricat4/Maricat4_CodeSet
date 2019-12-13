#ifndef _COMPLEX_
#define _COMPLEX_
class complex
{
private:
    double re;
    double im;
    friend complex& _doapl(complex*,const complex&);
public:
    complex(double &a=0,double &b=0)
    :real(a),img(b)
    {}
    complex& operator +=(const complex&);
    double real() const{return re;}
    double imag() const{return im;}
    ~complex();
};
complex&
complex::_doapl(complex *r,const complex& r1){
    r->re += r1.re;
    r->im += r1.im;
    return *r;
} 
//不是局部变量就能传引用
inline complex&
complex::operator +=(const complex  &r){
    return _doapl(this,r);
}
inline complex
operator + (const complex& x,const complex& y){
   return complex(x.real()+y.real(),x.imag()+y.imag());
}
inline complex
operator + (const complex& x,const double& y){
   return complex(x.real()+y,x.imag());
}
inline complex
operator + (const double& x,const complex& y){
   return complex(x+y.real(),y.imag());
}
#include<iostream>
inline ostream&
operator << (ostream& os,const complex& x){

}
#endif