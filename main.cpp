#include <iostream>
#include "Header.h"
using namespace std;

int main()
{ 
  char c[50];
  int ans = 0;
  char test_world[] = "Hello world aabbccd!";
  StringCls c1,c2;
  c1.strcpy_(test_world);
  std::cin >> c; 
  c2.strcpy_(c);
  ans = c1.FindString(c2);
  if(ans == -1){
    cout<<"沒有找到"<<endl;
  }else{
    cout<<"找到字串，位於原字串"<< ans <<"位置";
  }
}