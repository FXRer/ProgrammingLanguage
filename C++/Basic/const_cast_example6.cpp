// using mutable to remove the const-ness of the function...

#include <iostream>
using namespace std;


class Test
{
    // using mutable
    mutable int count;
    mutable const int* ptr;

    public:
        // read only function can't change const arguments.
        int funct(int num = 10) const
        {
            // should be a valid expression...
            count = num+=3;
            ptr = &num;
            cout<<"After some operation, the new value: "<<*ptr<<endl;

            return count;
        }

};

 
int main(void)
{
    Test var;

    cout<<"Initial value of the argument is: 10"<<endl;

    var.funct(10);

    return 0;
}
