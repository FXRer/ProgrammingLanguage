/* Sometimes implementation of all function cannot be provided in a base 
 * class because we don’t know the implementation. Such a class is 
 * called abstract class. 
 * 
 * A pure virtual function (or abstract function) in C++ is a virtual 
 * function for which we don’t have implementation, we only declare it. 
 * A pure virtual function is declared by assigning 0 in declaration.
*/

#include<iostream>
using namespace std;
 
class Base
{
    int x;
  public:
    virtual void fun() = 0;
    int getX() { return x; }
};
 
// This class ingerits from Base and implements fun()
class Derived: public Base
{
    int y;
public:
    void fun() { cout << "fun() called"; }
};
 
int main(void)
{
    Derived d;
    d.fun();
    return 0;
}

/* Some Interesting Facts:
 * 1) A class is abstract if it has at least one pure virtual function.
 * 2) We can have pointers and references of abstract class type.
 * 3) If we do not override the pure virtual function in derived class, 
 * then derived class also becomes abstract class.
 * 4) An abstract class can have constructors.
 */
