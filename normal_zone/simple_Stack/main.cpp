#include <iostream>
#include "Header_2.hpp" // 包含 Stack 類別的頭文件
using namespace std;

int main()
{
  // 創建一個整數型別的堆疊
  Stack<int> int_Stack(10); // 初始化堆疊容量為10

  for (int i = 1; i <= 10; i++)
  {
    int_Stack.Push(i);
  }
  int_Stack.cout_array();
  int int_sum = int_Stack.sum();
  cout << "sum=" << int_sum << endl;

  // 創建一個浮點數型別的堆疊
  Stack<float> float_Stack(10); // 初始化堆疊容量為10
  float j = 0.1;
  for (int i = 1; i <= 10; i++)
  {
    float_Stack.Push(j);
    j += 1;
  }
  float_Stack.cout_array();
  float float_sum = float_Stack.sum();
  cout << "sum=" << float_sum << endl;
  cout << "averages=" << float_sum / 10.0 << endl;

  Stack<Complex> complex_Stack(10); // 初始化堆疊容量為10
  float real = 1;
  float image = 1.1;
  Complex c(real, image);
  for (int i = 1; i <= 10; i++)
  {
    complex_Stack.Push(c);
    if (i < 10)
    {
      cout << complex_Stack.Top().GetReal() << "+" << complex_Stack.Top().GetImage() << "i"
           << ",";
    }
    else
    {
      cout << complex_Stack.Top().GetReal() << "+" << complex_Stack.Top().GetImage() << "i" << endl;
    }
    real += 1;
    image += 1.1;
    c.Set(real, image);
  }
  Complex complex_sum = complex_Stack.sum();
  cout << "sum=" << complex_sum.GetReal() << "+" << complex_sum.GetImage() << "i" << endl;

  return 0;
}