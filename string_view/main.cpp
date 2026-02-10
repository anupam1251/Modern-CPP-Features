#include <iostream>


void process1(const std::string & str){
    std::cout<<str.substr(0,4)<<'\n';

}

void process2(std::string_view str){
    std::cout<<str.substr(0,4)<<'\n';
}

int main() {

    std::string str2 = "Anupam";
    const char* str3 = "Anupam";

    
    process1("Anupam");
    process1(str2);
    process1(str3);
    process1(str2.substr(0,4));



    process2("Anupam");
    process2(str2);
    process2(str3);
    process2(str2.substr(0,4));

    return 0;
}