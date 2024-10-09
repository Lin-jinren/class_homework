#include <iostream>
#include <cmath>
using namespace std;

class complex
{
public:
    complex()
    {
        real = 0;
        image = 0;
        complex::rcount++;
    };

    complex(float r, float i)
    {
        real = r;
        image = i;
        complex::rcount++;
    };

    float GetReal() { return real; };
    float GetImage() { return image; };
    void Set(float r, float i)
    {
        real = r;
        image = i;
    };

    void operator=(complex c);
    bool operator==(complex c);
    static int rcount;

private:
    float real;
    float image;
};

void complex::operator=(complex c)
{
    real = c.GetReal();
    image = c.GetImage();
}
bool complex::operator==(complex c)
{
    if (real == c.GetReal() && image == c.GetImage())
        return true;
    else
        return false;
}
int complex::rcount = 0;

class complex_new : protected complex
{
public:
    complex_new() {};
    complex_new(float r, float i)
    {
        this->Set(r, i);
    }
    float abs();

    complex_new complex_new::operator*(complex_new &c)
    {
        //乘法
        return {(this->GetReal()*c.GetReal()) - (this->GetImage()*c.GetImage()),
            (this->GetReal()*c.GetImage()) + (this->GetImage()*c.GetReal())};
    };

    complex_new complex_new::operator+(complex_new &c)
    {
        //加法
        return {this->GetReal() + c.GetReal(), this->GetImage() + c.GetImage()};
    };

    complex_new complex_new::operator-(complex_new &c)
    {
        //減法

    };

protected:
private:
};

float complex_new::abs()
{
    float A = this->GetReal() * this->GetReal() + this->GetImage() * this->GetImage();
    return sqrt(A);
}

int main()
{
    complex c1(1, 2);
    complex c2(2, 3);
    complex *cp = new complex();

    int n,m;
    cout << "輸入長&寬 用空白分隔:";
    cin >> n >> m;
    complex_new *arr_cpc = new complex_new[n]; //一級指標陣列
    complex_new **arr_cp = new complex_new*[m]; //二級指標陣列


    cout << "There are " << complex::rcount << " were used." << endl;
    cout << c2.GetReal() << "+" << c2.GetImage() << "i" << endl;
    // cout << cp->GetReal() << "+" << cp->GetImage() << "i"<< endl;
    c2 = c1; // c2.operator=(c1);
    cout << c2.GetReal() << "+" << c2.GetImage() << "i" << endl;
    if (c2 == c1) // c2.operator==(c1)
    {
        cout << "c2 == c1" << endl;
    }
    else
    {
        cout << "c2 != c1" << endl;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; i<m; j++)
        {
            *(*(arr_cp+i)+j);//再去做加減
        };
    };
    
    

    complex_new cn1(2, 3);
    cout << "abs=" << cn1.abs() << endl;
    cn1.Set(3, 4);
    cout << "abs=" << cn1.abs() << endl;
    return 0;
}