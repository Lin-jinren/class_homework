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