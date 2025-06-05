// std::optional was introduced in C++17.
// It's not primarily for performance, but for improving code readability and safety
// by explicitly handling the presence or absence of a value.

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <optional>

using namespace std;
namespace fs = std::filesystem;

optional<string> readFile(const string& filepath) {

	ifstream file(filepath);

	if (!file) {
		return nullopt;
	}

	ostringstream ss;
	ss << file.rdbuf();

	string result = ss.str();
	return result;
}


int main() {

	optional<string> data = readFile("data.txt");
	string val = data.value_or("File not present");
	
	cout << val << '\n';
}