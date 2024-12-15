#include <iostream>
#include <vector>

void Print() {
	std::cout << "Hello World" << "\n";
}

int Add(int a, int b) {
	return a + b;
}

void PrintValue(int x) {
	std::cout << x << " ";
}
void ForEach(std::vector<int> v, void(*printPtr)(int)) {
	for (auto& val : v) {
		printPtr(val);
	}
}

int main() {
	Print();
	std::cout << Print << "\n";

	void(*funPtr)() = Print;
	funPtr();

	int(*addPtr)(int, int) = Add;
	std::cout<< addPtr(2, 3) << "\n";

	std::vector<int> v{ 5,9,4,6,8 };
	ForEach(v, PrintValue);


	return 0;
}