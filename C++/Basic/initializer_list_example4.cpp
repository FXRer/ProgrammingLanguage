/* 4) For initialization of base class members : Like point 3, 
 * parameterized constructor of base class can only be called using 
 * Initializer List.
 */
 
#include <iostream>
using namespace std;
 
class A {
    int i;
  public:
    A(int );
};
 
A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}
 
// Class B is derived from A
class B: A {
public:
    B(int );
};
 
B::B(int x):A(x) { //Initializer list must be used
    cout << "B's Constructor called";
}
 
int main() {
    B obj(10);
    return 0;
}



// Source: https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
