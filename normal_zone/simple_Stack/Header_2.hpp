#pragma once
#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class Complex
{
public:
  void Print();
  float GetReal();
  float GetImage();
  int Set(float re, float im);
  void operator=(Complex src);
  Complex operator+(Complex src);
  Complex &operator+=(const Complex &other);

  Complex();
  Complex(float re, float im);
  ~Complex(){};

private:
  float real = 0;
  float image = 0;
};

void Complex::Print()
{
  float x = 0;
  float y = 0;
  x = real;
  y = image;
  cout << x << "+" << y << "i";
}

float Complex::GetReal()
{
  return real;
}

float Complex::GetImage()
{
  return image;
}

int Complex::Set(float re, float im)
{
  real = re;
  image = im;
  return 0;
}

void Complex::operator=(Complex src)
{
  real = src.real;
  image = src.image;
}

Complex Complex::operator+(Complex src)
{
  Complex tmp;
  tmp.real = this->real + src.real;
  tmp.image = this->image + src.image;
  return tmp;
}

Complex &Complex::operator+=(const Complex &other)
{
  real += other.real;
  image += other.image;
  return *this;
}

Complex::Complex() // 建構子
{
  real = 0;
  image = 0;
}

Complex::Complex(float re, float im) // 建構子
{
  real = re;
  image = im;
}

// Stack實作部分
template <class T>
class Stack
{
public:
  Stack();
  ~Stack();
  Stack(int);

  bool IsEmpty();

  T &Top();
  void Push(T &);
  T Pop();
  T sum();
  void cout_array();

private:
  T *stack_elements;
  int top;
  int capacity;
};

template <class T>
inline Stack<T>::Stack()
{
  this->capacity = 5;
  stack_elements = new T[capacity];
  top = -1; // 初始化堆疊頂部指標為-1，表示堆疊是空的
}

template <class T>
Stack<T>::Stack(int capacity)
{
  this->capacity = capacity;
  stack_elements = new T[capacity];
  top = -1; // 初始化堆疊頂部指標為-1，表示堆疊是空的
}

template <class T>
Stack<T>::~Stack()
{
  delete[] stack_elements; // delete堆疊內存
}

template <class T>
bool Stack<T>::IsEmpty()
{
  return (top == -1); // 如果頂部指標為-1，堆疊是空的
}

template <class T>
T &Stack<T>::Top()
{
  if (IsEmpty())
  {
    throw std::runtime_error("堆疊是空的，無法獲取頂部元素");
  }
  return stack_elements[top];
}

template <class T>
void Stack<T>::Push(T &element)
{
  if (top == capacity - 1)
  {
    throw std::runtime_error("堆疊已滿，無法推進元素");
  }
  stack_elements[++top] = element; // 推進元素並更新頂部指標
}

template <class T>
T Stack<T>::Pop()
{
  if (IsEmpty())
  {
    throw std::runtime_error("堆疊是空的，無法彈出元素");
  }
  return stack_elements[top--]; // 彈出元素並更新頂部指標
}

template <class T>
T Stack<T>::sum() // 例外情況預設為5個
{
  T sum = T();
  for (int i = 0; i < 10; i++)
  {
    sum += stack_elements[i];
  }
  return sum;
}

template <class T>
void Stack<T>::cout_array() // 例外情況預設為5個
{
  for (int i = 0; i < 10; i++)
  {
    if (i < 9)
    {
      cout << stack_elements[i] << ",";
    }
    else
    {
      cout << stack_elements[i];
    }
  }
  cout << endl;
}
