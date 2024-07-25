#include <bits/stdc++.h>
#include "Bisection.hpp"
using namespace std;

Bisection::Bisection() {}
// Define the function for which we want to find the root
double Bisection::f(double x)
{
    return (2*(x*x)-1);
   // return ((x * x) - (4 * x) + 2); // Change this function according to your req.
}

// Bisection method function
double Bisection::BisectionMethod()
{
    // cout << "Enter the interval [a, b]: " << endl;
    // cin >> a >> b;
    if (f(a) * f(b) >= 0)
    {
        cout << "Bisection method failed, no root found within the given interval." << endl;
        return 0;
    }

    double c = a;
    while ((b - a) >= ToL)
    {
        // Find the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root
        if (f(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    // return c;
    this->root = c;
    cout << "The root is:: " << this->root << endl;
}
