#include <iostream>
#include <vector>
#include <thread>
#include <list>

std::vector<int> g_data;
std::list<int> g_list;
const int SIZE = 100000000;



class String {
public:
    String(){
        std::cout<<"String()"<<'\n';
    }
    
    String(const String&){
        std::cout<<"String(const String&)"<<'\n';
    }

    String& operator=(const String&){
        std::cout<<"operator=(const String&)"<<'\n';
        return *this;
    }

    ~String(){
        std::cout<<"~String()"<<'\n';
    }
};

void DownloadFile(String& file) {
    std::cout<<"[Downloading] started..."<<std::endl;
    for(int i = 0 ; i < SIZE ; i++){
        g_list.push_back(i);
    }
    std::cout<<"[Downloading] completed..."<<std::endl;
}
void DownloadFile1(const String& file) {
    std::cout<<"[Downloading] started..."<<std::endl;
    for(int i = 0 ; i < SIZE ; i++){
        g_list.push_back(i);
    }
    std::cout<<"[Downloading] completed..."<<std::endl;
}

int main() {

    std::cout<<"[Main] started..."<<std::endl;
;

    String file;
    std::thread t(DownloadFile, std::ref(file));


    std::thread t1(DownloadFile1, std::cref(file));
    t.join();
    t1.join();

    std::cout<<"[Main] completed..."<<std::endl;

    std::cin.get();

}