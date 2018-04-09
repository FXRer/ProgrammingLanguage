/* A shared_ptr is a container for raw pointers. It is a reference 
 * counting ownership model i.e. it maintains the reference count of its 
 * contained pointer in cooperation with all copies of the shared_ptr. 
 * So, the counter is incremented each time a new pointer points to the 
 * resource and decremented when destructor of object is called.
 * 
 * Reference Counting: It is a technique of storing the number of 
 * references, pointers or handles to a resource such as an object, 
 * block of memory, disk space or other resources.
 * 
 * An object referenced by the contained raw pointer will not be 
 * destroyed until reference count is greater than zero i.e. until all 
 * copies of shared_ptr have been deleted.
 * 
 * So, we should use shared_ptr when we want to assign one raw pointer 
 * to multiple owners.
 */

 // C++ program to demonstrate shared_ptr
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
    shared_ptr<A> p1 (new A);
    cout << p1.get() << endl;
    p1->show();
    shared_ptr<A> p2 (p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
 
    // Returns the number of shared_ptr objects
    //referring to the same managed object.
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
 
    // Relinquishes ownership of p1 on the object
    //and pointer becomes NULL
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;
 
    return 0;
}



/* OUTPUT:
 * 0x1c41c20
 * A::show()
 * A::show()
 * 0x1c41c20
 * 0x1c41c20
 * 2
 * 2
 * 0          // NULL
 * 1
 * 0x1c41c20
 */


   
/*
 * When to use shared_ptr?
 * 
 * Use shared_ptr if you want to share ownership of resource . Many 
 * shared_ptr can point to single resource. shared_ptr maintains 
 * reference count for this propose. when all shared_ptr’s pointing to 
 * resource goes out of scope the resource is destroyed.
 */


 
// Source : https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
  
