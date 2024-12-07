#include <iostream>

template<class T>
T square(T input) {
	return input * input;
}

auto square2(auto input) {
	return input * input;
}

template<typename T1, typename T2>
void foo(T1 input1, T2 input2) {
	std::cout << typeid(input1).name() << std::endl;
	std::cout << typeid(input2).name() << std::endl;
}

int main() {
	std::cout << square(5) << std::endl;
	std::cout << square(5.5) << std::endl;
	std::cout << square(6.5f) << std::endl;
	std::cout << square<double>(10.5) << std::endl;

	std::cout << square2(7) << std::endl;

	foo<int, float>(10, 3.5);


	return 0;
}