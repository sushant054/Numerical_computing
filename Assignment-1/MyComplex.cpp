#include <iostream>
#include<cmath>
#include "MyComplex.hpp"
using namespace std;

MyComplex::MyComplex()
{
    real = 0;
    img = 0;
}

void MyComplex::print()
{
    cout << real << "+" << img << "i";
}

void MyComplex::add(MyComplex c1, MyComplex c2)
{
    real = c1.real + c2.real;
    img = c1.img + c2.img;
}
void MyComplex::sub(MyComplex c1, MyComplex c2)
{
    real = c1.real - c2.real;
    img = c1.img - c2.img;
}
void MyComplex::mul(MyComplex c1, MyComplex c2)
{
    real = c1.real * c2.real;
    img = c1.img * c2.img;
}
void MyComplex::norm(MyComplex c)
{
    // The norm of a complex number a+bi is |a+bi| = sqrt(a^2 + b^2)
    double magnitude = sqrt(pow(c.real, 2) + pow(c.img, 2));
    cout << "Norm: " << magnitude << endl;
}
void MyComplex::compexConjugate()
{
    // The complex conjugate of a complex number a+bi is a-bi
    cout << "Complex Conjugate: " << real << "-" << img << "i" << endl;
}