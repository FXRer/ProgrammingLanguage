// demonstrates the type casting

#include <iostream>
using namespace std;

class One
{
    public:

    void funct()
    {cout<<"Testing..."<<endl;};
};

// const and volatile...
const volatile int* Test1;

// const...
const int* Test2;

void TestConstVol()
{
    One Test3;

    // remove the const...
    const_cast<One&>(Test3).funct();

    // remove const and volatile...
    const_cast<int*> (Test1);
}

 
int main()
{
    TestConstVol();

    return 0;
}
