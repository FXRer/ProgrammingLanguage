#include <iostream>
#include <thread>

void thread_function()
{
   for(int i = 0; i < 10000; i++);
       std::cout<<"thread_function executing"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    for(int i = 0; i < 10000; i++);
        std::cout<<"Display from main thread"<<std::endl;

    threadObj.join();
    std::cout<<"Exit of main() function"<<std::endl;
    return 0;
}

