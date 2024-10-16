#pragma once
#include <iostream>
#include <cstring>
#include <math.h>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

class Complex
{
public:
  void Print();
  float GetReal() const;
  float GetImage() const;
  Complex GetSelf() const;
  void Set(float re, float im);
  void Set(Complex src);
  //上面等效於->void operator=(Complex src);

  Complex();
  Complex(float re, float im);
  ~Complex(){};

private:
  float real = 0;
  float image = 0;
};

class Complex_New : protected Complex
{
  public:
    Complex_New();
    Complex_New(float,float);
    Complex_New(Complex);
    ~Complex_New(){};

    float abs();
    
    void operator=(Complex_New src);
    Complex_New operator+(Complex_New src);
    Complex_New operator-(Complex_New src);
    Complex_New operator*(Complex_New src);
    Complex_New operator/(Complex_New src);
    Complex_New &operator+=(Complex_New &other);
    friend std::ostream& operator<<(std::ostream& os, const Complex_New& obj);
};