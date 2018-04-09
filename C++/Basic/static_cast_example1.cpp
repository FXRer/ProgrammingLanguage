 #include <iostream>

using namespace std;

int main()
{
       int sum = 1000;
       int count = 21;

       double average1 = sum/count;
       cout<<"Before conversion = "<<average1<<endl;

       double average2 = static_cast<double>(sum)/count;
       cout<<"After conversion  = "<<average2<<endl;

       return 0;

}
