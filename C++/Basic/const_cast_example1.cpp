// demonstrates the const_cast

#include <iostream>
using namespace std;

 
int main()
{
   // p = 20 is a constant value, cannot be modified
   const int p = 20;

   cout<<"const p = "<<p<<"\nq = p + 20 = "<<(p + 20)<<endl;

   // the following code should generate error, because
   // we try to modify the constant value...
   // uncomment, recompile and re run, notice the error...
   //p = 15;
   //p++;

   // remove the const...
   int r = const_cast<int&> (p);

   // the value of 20 should be modified now...
   --r;

   cout<<"Removing the const, decrement by 1,\nNew value r = "<<r<<"\np = " <<p<<endl;

   return 0;
}
