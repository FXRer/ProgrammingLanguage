// removing the const-ness of the 'this' pointer

#include <iostream>
using namespace std;

class Test
{
    public:
        void GetNumber(int);

        // read only function...
        void DisplayNumber() const;

    private:
        int Number;
};

 
void Test::GetNumber(int Num)
{Number = Num;}

 
void Test::DisplayNumber() const
{
    cout<<"\nBefore removing const-ness: "<<Number;

    const_cast<Test*>(this)->Number+=2;
    cout<<"\nAfter removing const-ness: "<<Number<<endl;
}

int main()
{
    Test p;

    p.GetNumber(20);

    p.DisplayNumber();

    return 0;
}
