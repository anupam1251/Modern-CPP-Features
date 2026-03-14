#include <iostream>
#include <thread>

// Detached thread holds reference to local variable temp.
// When oops() returns, temp is destroyed while thread may still access it.
// This leads to a dangling reference and undefined behavior.

// here detached thread may never get CPU time to run.(sometimes will not print "hello")

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
    mythread.detach();
}

int main() {
    oops();
    // std::cin.get();
}