#include <iostream>
#include <thread>
#include <algorithm>


class WorkerThread
{
public:
    void operator()()     
    {
        std::cout<<"Worker thread "<<std::this_thread::get_id()<<" is executing"<<std::endl;
    }
};

int main()  
{
    std::vector<std::thread> threadList;
    for(int i = 0; i < 10; i++)
    {
        threadList.push_back( std::thread( WorkerThread() ) );
    }
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    std::cout<<"Waiting for all the worker threads to finish"<<std::endl;
    std::for_each(threadList.begin(),threadList.end(), std::mem_fn(&std::thread::join));
    std::cout<<"Exiting from Main thread"<<std::endl;
    return 0;
}

