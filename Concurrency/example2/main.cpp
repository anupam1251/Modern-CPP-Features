#include <iostream>
#include <list>
#include <thread>
#include <mutex>


std::list<int> g_data;
const int SIZE {10000};

std::mutex g_mtx;

void Download1(){
    for(int i = 0 ; i < SIZE ; i++){
        g_mtx.lock();
        g_data.push_back(i);
        if(i == 500) return ;
        g_mtx.unlock();
    }
}

void Download2(){
    for(int i = 0 ; i < SIZE ; i++){
        g_mtx.lock();
        g_data.push_back(i);
        g_mtx.unlock();
    }
}


int main() {
    std::thread t1(Download1);
    std::thread t2(Download2);

    t1.join();
    t2.join();

    std::cout<<g_data.size()<<'\n';
}
