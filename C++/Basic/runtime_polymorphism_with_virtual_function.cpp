/* The idea is, virtual functions are called according to the type of 
 * object pointed or referred, not according to the type of pointer or 
 * reference. In other words, virtual functions are resolved late, at 
 * runtime. 
 */

#include<iostream>
using namespace std;
  
class Base
{
public:
    virtual void show() { cout<<" In Base \n"; }
};
  
class Derived: public Base
{
public:
    void show() { cout<<"In Derived \n"; }
};
  
int main(void)
{
    Base *bp = new Derived;
    bp->show();  // RUN-TIME POLYMORPHISM
    return 0;
}

/* What is the use?
 * 
 * Virtual functions allow us to create a list of base class pointers 
 * and call methods of any of the derived classes without even knowing 
 * kind of derived class object. For example, consider a employee 
 * management software for an organization, let the code has a simple 
 * base class Employee , the class contains virtual functions like 
 * raiseSalary(), transfer(), promote(),.. etc. Different types of 
 * employees like Manager, Engineer, ..etc may have their own 
 * implementations of the virtual functions present in base class 
 * Employee. In our complete software, we just need to pass a list of 
 * employees everywhere and call appropriate functions without even 
 * knowing the type of employee. For example, we can easily raise salary 
 * of all employees by iterating through list of employees. Every type 
 * of employee may have its own logic in its class, we don’t need to 
 * worry because if raiseSalary() is present for a specific employee 
 * type, only that function would be called.
 */
 
#if 0
class Employee
{
public:
    virtual void raiseSalary()
    {  /* common raise salary code */  }
 
    virtual void promote()
    { /* common promote code */ }
};
 
class Manager: public Employee {
    virtual void raiseSalary()
    {  /* Manager specific raise salary code, may contain
          increment of manager specific incentives*/  }
 
    virtual void promote()
    { /* Manager specific promote */ }
};
 
// Similarly, there may be other types of employees
 
// We need a very simple function to increment salary of all employees
// Note that emp[] is an array of pointers and actual pointed objects can
// be any type of employees. This function should ideally be in a class 
// like Organization, we have made it global to keep things simple
void globalRaiseSalary(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
        emp[i]->raiseSalary(); // Polymorphic Call: Calls raiseSalary() 
                               // according to the actual object, not 
                               // according to the type of pointer                                 
}

#endif //0

/* See more at : https://www.geeksforgeeks.org/virtual-functions-and-
 * runtime-polymorphism-in-c-set-1-introduction/
 */
