#include <iostream>
using namespace std;

class Fraction{
    private:
        int m_num;
        int m_denum;
    public:
        Fraction(int a,int den=1):m_num(a),m_denum(den){}
        operator double() const{
            cout<<(double)(m_num)/m_denum<<endl;
            return (double)(m_num)/m_denum;
        }
        int M_num() const{
            return m_num;
        }
        int M_denum() const{
            return m_denum;
        }
        Fraction operator+(const Fraction &ths){
            cout<<this->m_num*ths.M_denum()+this->m_denum*ths.M_num()<<"/"<<this->m_denum*ths.M_denum()<<endl;
            return Fraction(this->m_num*ths.M_denum()+this->m_denum*ths.M_num(),this->m_denum*ths.M_denum());
        }

};
int main(){
    Fraction f(3,5);
    Fraction d = f + 4;
    //cout<<"d:"<<d<<endl;
    return 0;
}