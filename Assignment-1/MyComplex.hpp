 // Class is a template...
class MyComplex
{
public:
    double real;
    double img;

    // Default constructor
    MyComplex();

    // Function to print complex number
    void print();

    void add(MyComplex, MyComplex);
    void sub(MyComplex, MyComplex);
    void mul(MyComplex, MyComplex);
    void div(MyComplex, MyComplex);
    void norm(MyComplex);
    void compexConjugate();

};
