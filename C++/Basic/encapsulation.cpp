/* In Object Oriented Programming, Encapsulation is defined as binding 
 * together the data and the functions that manipulates them.
 * 
 * In C++ encapsulation can be implemented using Class and access 
 * modifiers (private, protected, public).  
 */
 
#include<iostream>
using namespace std;
 
class Encapsulation
{
    private:
        // data hidden from outside world
        int x;
         
    public:
        // function to set value of 
        // variable x
        void set(int a)
        {
            x =a;
        }
         
        // function to return value of
        // variable x
        int get()
        {
            return x;
        }
};
 
// main function
int main()
{
    Encapsulation obj;
     
    obj.set(5);
     
    cout<<obj.get();
    return 0;
}
