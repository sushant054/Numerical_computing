class Bisection
{
public:
    double a = 0;
    double b = 1;
    // double c;
    double ToL = 0.00001;
    double root;

    Bisection();

    double f(double);
    double BisectionMethod();
};