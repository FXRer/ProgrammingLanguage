 #include <iostream>

using namespace std;

// enum data type
enum color {blue, yellow, red, green, magenta};

int main()
{
       int p1 = 3;

       cout<<"integer type, p1 = "<<p1<<endl;
       cout<<"color c1 = static_cast<color> (p1)"<<endl;
       color c1 = static_cast<color> (p1);

       cout<<"enum type, c1 = "<<c1<<endl;

       return 0;

}
