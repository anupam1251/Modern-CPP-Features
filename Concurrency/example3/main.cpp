#include <iostream>
#include <list>
#include <thread>
#include <mutex>

// lock_guard releases the lock in destructor.
// It is a C++ programming idioms called RAII (Resource Acquisition Is Initialization) which is used to manage resources such as memory, file handles, mutex locks etc. 
// It ensures that the resource is properly released when it goes out of scope, even if an exception is thrown.

std::list<int> g_data;
const int SIZE {10000};

std::mutex g_mtx;

void Download1() {
    for(int i = 0 ; i < SIZE ; i++){
        std::lock_guard<std::mutex> lock(g_mtx);
        if(i == 500) return ; 
        g_data.push_back(i);
    }
}

void Download2() {
    for(int i = 0 ; i < SIZE ; i++){
        std::lock_guard<std::mutex> lock(g_mtx);
        g_data.push_back(i);
    }
    std::this_thread::sleep_for(std::chrono::seconds(40)); // to simulate some work after lock is released
}

int main() {

    std::thread t1(Download1);
    std::thread t2(Download2);
    auto x = t2.get_id();
    std::cout<<"Thread id: "<<x<<'\n';

    t1.join();
    t2.join();

    std::cout<<g_data.size()<<'\n';
}