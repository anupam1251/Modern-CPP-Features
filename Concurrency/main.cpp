#include <iostream>
#include <vector>
#include <thread>

std::vector<int> g_data;
const int SIZE = 1000000000;

void DownloadFile() {
    std::cout<<"[Downloading] started..."<<std::endl;
    for(int i = 0 ; i < SIZE ; i++){
        g_data.push_back(i);
    }
    std::cout<<"[Downloading] completed..."<<std::endl;
}

int main() {

    std::cout<<"[Main] started..."<<std::endl;
    // DownloadFile();

    std::thread t(DownloadFile);
    t.detach();
    // if(t.joinable()){
    //     t.join();
    // }
    std::cout<<"[Main] completed..."<<std::endl;

    std::cin.get();

    // system("pause");
    // return 0;
}