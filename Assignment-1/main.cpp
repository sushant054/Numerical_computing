// #include <iostream>
// #include "MyComplex.hpp"
// using namespace std;
// //class is a templete
// class MyComplex{
//     public:
// double real;//it is bad to assign a values here(it is syntatically allowed...but logically wrong)
// double img;
// //default constructor
// MyComplex(){
//     cout<<"\n in constructor MyComplex()\n";
// real=0;
// img=0;
// }
// void print()
// {
//     cout<<real<< "+" <<img<< "i";
//     // cout<<"\n real::"<< real <<"\t img :: "<< img<< endl;
// }
// };
// int main()
// {
//     MyComplex c1;
//     c1.real=10;
//     c1.img=5;
//     cout<<endl;
//     c1.print();
//     // cout<<"\n c1.real::"<<c1.real<<"\t c1.img :: "<< c1.img<< endl;
//     cout<<endl;
//     return 0;
// } // namespace std;
#include <iostream>

#include "MyComplex.hpp"

using namespace std;

int main()
{
    MyComplex c1, c2, c3,c4,c5 ;

    c1.print();

    c1.real = 10;
    c1.img = 5;

    cout << endl;
    c1.print();
    cout << endl;

    c2.real = 2;
    c2.img = 3;
    cout << endl;

    c2.print();
    cout << endl;
    cout << "addition:\n";
    c3.print();
    cout << endl;

    c3.add(c1, c2);

    c3.print();
    cout << endl;
    //for substraction
    cout << "substraction:\n";
    c4.print();
    cout << endl;

    c3.sub(c1, c2);

    c3.print();
    cout << endl;
    cout << "multiplication:\n";
    //for multiplication
    c5.print();
    cout << endl;

    c3.mul(c1, c2);

    c3.print();
    cout << endl;
    //for norm
    //c3.norm();
    //c3.compexConjugate();
   

    return 0;
}