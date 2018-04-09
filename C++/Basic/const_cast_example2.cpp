// demonstrates const_cast

#include <iostream>
using namespace std;

struct One
{
   // test function...
   void funct1()
   { cout<<"Testing..."<<endl;}
};

// const argument, cannot be modified...
void funct2(const One& c)
{
   // will generate warning/error...
   c.funct1();
}

int main()
{
   One b;

   funct2(b);

   return 0;
}
