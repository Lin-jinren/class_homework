#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS

StringCls::StringCls() : data(nullptr), len(0)
{
  // 藍圖構建的時候預先設定隱藏屬性，nullptr為標準指標空值寫法
}

StringCls::~StringCls()
{
}

void StringCls::strcpy_(char *src)
{
  if (data != nullptr)
    delete[] data;
  len = std::strlen(src);
  data = new char[len + 1];
  data = strcpy(data, src);
}

void StringCls::strcat_(char *src)
{
  int new_len = len + strlen(src);        // 串接長度
  char *new_data = new char[new_len + 1]; // 新字串陣列 並多增加一位\0

  if (data != nullptr)
  {
    // 複製原始資料到新的陣列
    std::strcpy(new_data, data);
  }

  // 附加新的字串
  std::strcat(new_data, src);

  // 釋放舊的記憶體
  delete[] data;

  // 將新的記憶體指派給 data
  data = new_data;
  len = new_len;
}

unsigned int StringCls::strien_()
{
  len = std::strlen(data); // 找長度
  return len;
}

char *StringCls::GetString()
{
  return data;
}

int StringCls::PrintString()
{
  std::cout << data; // 輸出字串
  return 0;
}

int StringCls::FindString(StringCls pht)
{
  int ans = -1;                                  // 設定找不到的回應值
  for (int i = 0; i <= this->len - pht.len; i++) // 從頭比到尾 但不超過原始自串的底線
  {
    for (int j = 0; j < pht.len; j++)
    {
      if (this->data[i + j] != pht.data[j])
      {
        break; // 不相符，內層迴圈結束
      }
      if (j == pht.len - 1)
      {
        ans = i; // 找到匹配，設定答案並結束外層迴圈
        break;
      }
    }
    if (ans != -1)
    {
      break;
    }
  }
  return ans;
}

void StringCls::operator=(StringCls src)
{ // 以下傳入值為等號後方 作用於等號前方
  if (data != nullptr)
  {
    delete[] data;  // 刪除自身已存在字串
    data = nullptr; // 將指標設為 nullptr
  }
  len = src.len;
  data = new char[len + 1];
  std::strcpy(data, src.data);
}

StringCls StringCls::operator+(const StringCls &src)
{ // 定值參考傳入，可以防止修改到原資料
  StringCls tmp;
  tmp.len = len + src.len;
  tmp.data = new char[tmp.len + 1];

  std::strcpy(tmp.data, data);
  std::strcat(tmp.data, src.data);

  return tmp;
}
