#include <iostream>
#include <thread>
int main()  
{
    int x = 9;
    std::thread threadObj([]{
        for(int i = 0; i < 10000; i++)
            std::cout<<"Thread executing"<<std::endl;
        });
            
    for(int i = 0; i < 10000; i++)
        std::cout<<"Display from main()"<<std::endl;
        
    threadObj.join();
    std::cout<<"Exiting from main() function"<<std::endl;


    return 0;
}
