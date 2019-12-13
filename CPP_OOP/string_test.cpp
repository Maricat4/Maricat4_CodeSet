#include "string.h"
#include <iostream>

using namespace std;

int main()
{
  String s1("hello"); 
  String s2("world");
    
  String s3(s2);
  cout << s3 << endl;
  
  s3 = s1;
  cout << s3 << endl;     
  cout << s2 << endl;  
  cout << s1 << endl;    

  String s4;
  int a = sizeof(s4);
  cout <<  a << endl;    
  cout << s4 << endl;    
  system("pause");
  return  0; 
}
