#include "simple_cpx.hpp"

void Complex::Print()
{
  cout << real << "+" << image << "i";
};

float Complex::GetReal() const
{
  return real;
};

float Complex::GetImage() const
{
  return image;
};

Complex Complex::GetSelf() const
{
  return *this;
};

void Complex::Set(float re, float im)
{
  real = re;
  image = im;
};

void Complex::Set(Complex src)
{
  real = src.GetReal();
  image = src.GetImage();
};

Complex::Complex() // 建構子
{
  real = 0;
  image = 0;
};

Complex::Complex(float re, float im) // 建構子
{
  real = re;
  image = im;
};

//========================

Complex_New::Complex_New(){};

Complex_New::Complex_New(float re, float im)
{
  this->Set(re,im);
};

Complex_New::Complex_New(Complex src)
{
  this->Set(src.GetReal(),src.GetImage());
};

float Complex_New::abs() //計算模
{
  return sqrtf(powf(GetReal(),2)+powf(GetImage(),2));
};

void Complex_New::operator=(Complex_New src)
{
  this->Set(src.GetSelf());
}

Complex_New Complex_New::operator+(Complex_New src)
{
  Complex_New temp;
  temp.Set(this->GetReal()+src.GetReal(),this->GetImage()+src.GetImage());
  return temp;
};

Complex_New Complex_New::operator-(Complex_New src)
{
  Complex_New temp;
  temp.Set(this->GetReal()-src.GetReal(),this->GetImage()-src.GetImage());
  return temp;
};

Complex_New Complex_New::operator*(Complex_New src)
{
  Complex_New temp;
  float a,b,c,d;
  a = this->GetReal();
  b = this->GetImage();
  c = src.GetReal();
  d = src.GetImage();

  temp.Set(a*c-b*d,a*d+b*c);
  return temp;
};

Complex_New Complex_New::operator/(Complex_New src)
{
  Complex_New temp;
  float a,b,c,d,t;
  a = this->GetReal();
  b = this->GetImage();
  c = src.GetReal();
  d = src.GetImage();
  t = c*c+d*d;

  temp.Set((a*c+b*d)/t,(b*c-a*d)/t);
  return temp;
}

Complex_New &Complex_New::operator+=(Complex_New &other) {
  this->Set(this->GetReal()+other.GetReal(),this->GetImage()+other.GetImage());
  return *this;
};

std::ostream &operator<<(std::ostream &os, const Complex_New &obj)
{
  os << obj.GetReal() << "+" << obj.GetImage() << "i";
  return os;
}