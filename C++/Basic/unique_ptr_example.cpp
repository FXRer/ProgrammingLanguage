/* std::unique_ptr was developed in C++11 as a replacement for 
 * std::auto_ptr.
 * 
 * unique_ptr is a new facility with a similar functionality, but with 
 * improved security (no fake copy assignments), added features 
 * (deleters) and support for arrays. It is a container for raw 
 * pointers. It explicitly prevents copying of its contained pointer as 
 * would happen with normal assignment i.e. it allows exactly one owner 
 * of the underlying pointer.
 * 
 * So, when using unique_ptr there can only be at most one unique_ptr at 
 * any one resource and when that unique_ptr is destroyed, the resource 
 * is automatically claimed. Also, since there can only be one 
 * unique_ptr to any resource, so any attempt to make a copy of 
 * unique_ptr will cause a compile time error.
 * 
 * unique_ptr<A> ptr1 (new A);
 * // Error: can't copy unique_ptr
 * unique_ptr<A> ptr2 = ptr1; 
 * 
 * But, unique_ptr can be moved using the new move semantics i.e. using 
 * std::move() function to transfer ownership of the contained pointer 
 * to another unique_ptr.
 * 
 * // Works, resource now stored in ptr2
 * unique_ptr<A> ptr2 = move(ptr1); 
 * 
 * So, it’s best to use unique_ptr when we want a single pointer to an 
 * object that will be reclaimed when that single pointer is destroyed. 
 */

// C++ program to illustrate the use of unique_ptr
#include<iostream>
#include<memory>
using namespace std;
 
class A
{
public:
    void show()
    {
        cout<<"A::show()"<<endl;
    }
};
 
int main()
{
    unique_ptr<A> p1 (new A);
    p1 -> show();
 
    // returns the memory address of p1
    cout << p1.get() << endl;
 
    // transfers ownership to p2
    unique_ptr<A> p2 = move(p1);
    p2 -> show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
 
    // transfers ownership to p3
    unique_ptr<A> p3 = move (p2);
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
 
    return 0;
}




/* OUTPUT:
 * A::show()
 * 0x1c4ac20
 * A::show()
 * 0          // NULL
 * 0x1c4ac20
 * A::show()
 * 0          // NULL
 * 0          // NULL
 * 0x1c4ac20
 */
 
 
 
  
/* The below code returns a resource and if we don’t explicitly capture 
 * the return value, the resource will be cleaned up. If we do, then we
 * have exclusive ownership of that resource. In this way we can think 
 * of unique_ptr as safer and better replacement of auto_ptr.
 *
 * unique_ptr<A> fun()
 * {
 *     unique_ptr<A> ptr(new A);
 * 
 *     ...
 * 
 *     return ptr;
 * }
 * 
 * When to use unique_ptr?
 * 
 * Use unique_ptr when you want to have single ownership(Exclusive) of 
 * resource. Only one unique_ptr can point to one resource. Since there 
 * can be one unique_ptr for single resource its not possible to copy 
 * one unique_ptr to another.




// Source : https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/

