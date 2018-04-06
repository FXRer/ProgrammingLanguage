/* The mutable storage class specifier in C++ (or use of mutable keyword 
 * in C++)
 * auto, register, static and extern are the storage class specifiers 
 * in C. 
 * typedef is also considered as a storage class specifier in C. 
 * C++ also supports all these storage class specifiers. 
 * In addition to this C++, adds one important storage class specifier 
 * whose name is mutable.

 * What is the need of mutable?
 * Sometimes there is requirement to modify one or more data members of 
 * class / struct through const function even though you don’t want the 
 * function to update other members of class / struct. This task can be 
 * easily performed by using mutable keyword. Consider this example 
 * where use of mutable can be useful. Suppose you go to hotel and you 
 * give the order to waiter to bring some food dish. After giving order, 
 * you suddenly decide to change the order of food. Assume that hotel 
 * provides facility to change the ordered food and again take the order 
 * of new food within 10 minutes after giving the 1st order. After 10 
 * minutes order can’t be cancelled and old order can’t be replaced by 
 * new order. See the following code for details.
 * 
 * The keyword mutable is mainly used to allow a particular data member 
 * of const object to be modified. When we declare a function as const, 
 * the this pointer passed to function becomes const. Adding mutable to 
 * a variable allows a const pointer to change members.
 * 
 * mutable is particularly useful if most of the members should be 
 * constant but a few need to be updateable. Data members declared as 
 * mutable can be modified even though they are the part of object 
 * declared as const. You cannot use the mutable specifier with names 
 * declared as static or const, or reference.
*/

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Customer {
    char name[25];
    mutable char placedOrder[50];
    int tableNumber;
    mutable int bill;
	
  public:
	Customer (char* s, char* m, int a, int p) {
        strcpy(name, s);
        strcpy(placedOrder, m);
        tableNumber = a;
        bill = p;		
	}

    void changePlacedOrder (char* p) const {
        strcpy(placedOrder, p);
	}

    void changeBill (int s) const {
        bill = s;
	}

    void display() const {
        cout << "Customer name is: " << name << endl;
        cout << "Food ordered by customer is: " << placedOrder << endl;
        cout << "Table number is: " << tableNumber << endl;
        cout << "Total payable amount: " << bill << endl;
    }
};


int main()
{
    const Customer c1("Pravasi Meet", "Ice Cream", 3, 100);
    c1.display();
    c1.changePlacedOrder("GulabJammuns");
    c1.changeBill(150);
    c1.display();
    
    return 0;
}
