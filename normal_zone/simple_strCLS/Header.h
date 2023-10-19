#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

// StringCLS實作部分
class StringCls
{
public:
  StringCls();
  ~StringCls();
  void strcpy_(char *src);
  void strcat_(char *src);
  unsigned int strien_();
  char *GetString();
  int PrintString();

  int FindString(StringCls pht);

  void operator=(StringCls src);
  StringCls operator+(const StringCls &src);

private:
  char *data;
  int len;
};