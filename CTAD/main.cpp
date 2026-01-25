#include <iostream>
#include <vector>
// CTAD - Class Template Argument Deduction - introduced in c++17

using namespace std::string_literals;

int main(){

    std::vector v1 {10,20,30}; // CTAD deduces element type as int to std::vector<int>

    std::cout<<typeid(*v1.begin()).name() <<'\n';

    // std::vector v2 {10,20,30.5}; //compilation error (mixed datatypes)

    std::vector v2 {"Anupam", "C++", ""};
    std::cout<<typeid(v2[0]).name()<<'\n';  // const char* (PKc)

    std::vector v3 {"Anupam"s, "C++"s, ""s};
    std::cout<<typeid(v3[0]).name()<<'\n';  //string


}