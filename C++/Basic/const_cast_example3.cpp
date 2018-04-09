// demonstrates the type casting

#include <iostream>
using namespace std; 

double funct1(double& f)
{
    // do some work here...
    f++;

    cout<<"f = "<<f<<endl;
    // return the incremented value...

    return f;
}

// const argument, can't be modified...
void funct2(const double& d)
{
    cout<<"d = "<<d<<endl;
       
    // remove the const, use the non-const argument, making function call...
    double value = funct1(const_cast<double&> (d));

    // display the returned value...
    cout<<"value = "<<value<<endl;
}

int main()
{
    double c = 4.324;

    // first function call...
    funct2(c);

    return 0;
}
