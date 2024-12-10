#include <iostream>
#include <map>

//using an alias
using MapNameAge = std::map<std::string, int> ;
int main() {
	
	MapNameAge mapNameAge;

	mapNameAge.emplace("Anupam", 26);
	mapNameAge.emplace("John", 21);
	mapNameAge.emplace("David", 23);
	mapNameAge.emplace("Micheal", 20);

	//structured binding (c++17 or later)
	for (const auto& [name, age] : mapNameAge) {
		std::cout << "Name : " << name << "\t Age : " << age << "\n";
	}

	std::cout << "\n\n\n";
	//pair access method before c++17
	for (const auto& pair : mapNameAge) {
		std::cout << "Name : " << pair.first << "\t Age : " << pair.second << "\n";
	}

}