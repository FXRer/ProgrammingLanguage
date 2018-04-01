#include <iostream>
#include <thread>

class DisplayThread
{
    public:
        void operator()()
        {
            for(int i = 0; i < 10000; i++)
                std::cout<<"DisplayThread executing"<<std::endl;
        }
};

int main()  
{
    std::thread threadObj( (DisplayThread()) );
    for(int i = 0; i < 10000; i++)
        std::cout<<"Display from main thread "<<std::endl;

    std::cout<<"Waiting for DisplayThread to complete"<<std::endl;
    threadObj.join();
    std::cout<<"Exiting from main() function"<<std::endl;
    return 0;
}

