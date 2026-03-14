#include <iostream>
#include <thread>

// thread_guard class is a classic RAII wrapper to ensure a thread is joined safely

class thread_guard{
    std::thread& t;
public:
    thread_guard(std::thread& _t) : t(_t) {}
    ~thread_guard(){
        if(t.joinable())
            t.join();
    }

    thread_guard(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};


void do_something(int i){
    std::cout<<"hello"<<'\n';
    return ;
}

class Fun{
    int& i;
public:
    Fun(int& _i) : i(_i){}
    void operator()(){
        for(int j = 0 ; j < 100000 ; j++){
            do_something(i);
        }
    }
};

void oops(){
    int temp = 0;
    Fun myobj(temp);
    std::thread mythread(myobj);
    thread_guard tg(mythread);
}

int main() {
    oops();
    // std::cin.get();
}