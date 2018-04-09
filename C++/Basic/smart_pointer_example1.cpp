/* Using smart pointers, we can make pointers to work in way that we 
 * don’t need to explicitly call delete. Smart pointer is a wrapper 
 * class over a pointer with operator like * and -> overloaded. The 
 * objects of smart pointer class look like pointer, but can do many 
 * things that a normal pointer can’t like automatic destruction (yes, 
 * we don’t have to explicitly use delete), reference counting and more.
 * The idea is to make a class with a pointer, destructor and overloaded 
 * operators like * and ->. Since destructor is automatically called 
 * when an object goes out of scope, the dynamically allocated memory 
 * would automatically deleted (or reference count can be decremented). 
 * Consider the following simple smartPtr class.
 */
 
#include<iostream>
using namespace std;
 
class SmartPtr
{
   int *ptr;  // Actual pointer
  public:
   // Constructor: Refer https://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword 
   explicit SmartPtr(int *p = NULL) { ptr = p; } 
 
   // Destructor
   ~SmartPtr() { delete(ptr); }  
 
   // Overloading dereferencing operator
   int &operator *() {  return *ptr; }
};
 
int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
 
    // We don't need to call delete ptr: when the object 
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.
 
    return 0;
}


/* OUTPUT:
 * 20
 */


// Source: https://www.geeksforgeeks.org/smart-pointers-cpp/
