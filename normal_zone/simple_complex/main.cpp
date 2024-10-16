#include "simple_cpx.hpp"

int main()
{
  std::srand(std::time(0));
  short l;
  cout << "type your Array length:";
  cin >> l;

  Complex_New** a = new Complex_New*[2];
  Complex_New* b = new Complex_New[l];
  Complex_New c = Complex_New();

  for(int i = 0; i < 2; ++i)
  {
    a[i] = new Complex_New[l];
    for(int j = 0; j < l; ++j)
    {
      cout << "type real and image: ";
      float x ;
      float y ; 
      cin >> x >> y;
      *(*(a+i)+j) = Complex_New(x,y);
    };
  };

  for (int i = 0; i < l; ++i) {
    *(b+i) = *(*(a+0)+i) + *(*(a+1)+i); //相加
  };

  for (int i = 0; i < l; ++i) {
    c = c + (*(*(a+0)+i) * *(*(a+1)+i));
  };

  cout << "點積結果: " << c << endl;
  cout << "點積結果的模: " << c.abs() << endl;
  cout << "相加結果: " << "[ ";
  for(int i = 0; i < l; ++i)
  {
    cout << *(b+i) << " ";
  };
  cout << "]" << endl;

  cout << "a[0]矩陣的模: " << "[ ";
  for(int i = 0; i < l; ++i)
  {
    cout << (*(*(a+0)+i)).abs() << " ";
  };
  cout << "]" << endl;

  cout << "a[1]矩陣的模: " << "[ ";
  for(int i = 0; i < l; ++i)
  {
    cout << (*(*(a+0)+i)).abs() << " ";
  };
  cout << "]" << endl;

  //拆家
  for (int i = 0; i < 2; ++i) {
    delete[] a[i];
  }
  delete[] a;
  delete[] b;

  return 0;
}