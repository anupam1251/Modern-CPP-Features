#include <iostream>
#include <thread>
#include <chrono>

// thread library functions

void Process() {
    
    auto id = std::this_thread::get_id();
    std::cout<<id<<'\n';
    for(int i = 0 ; i < 10 ; ++i){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<i<<" "<<std::endl;

    }

}

int main() {

    std::thread t(Process);

    auto id = t.get_id();
    std::cout<<"t.get_id() : "<<id<<'\n';

    auto cores = std::thread::hardware_concurrency();
    std::cout<<"Cores : "<<cores<<'\n';

    pthread_t handle = t.native_handle();
    pthread_setname_np(handle, "ProcessThread");

    t.join();
}