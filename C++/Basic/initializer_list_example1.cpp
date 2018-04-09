/* 1) For initialization of non-static const data members:
 * const data members must be initialized using Initializer List. In the
 * following example, “t” is a const data member of Test class and is 
 * initialized using Initializer List.
 */

#include<iostream>
using namespace std;
 
class Test {
    const int t;
  public:
    Test(int t):t(t) {}  //Initializer list must be used
    int getT() { return t; }
};
 
int main() {
    Test t1(10);
    cout<<t1.getT()<< endl;
    return 0;
}
 
 
 
/* OUTPUT:
   10 
*/



// Source: https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
